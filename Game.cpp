//
// Created by Michał Sutowicz on 01/02/2022.
//

#include "Game.h"
#include "Food.h"
#include "Ghost.h"
#include "ncurses.h"
#include "string"
#include <unistd.h>
using std::string, std::vector;
void Game::init() {
  initscr();
  start_color();
  curs_set(0);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  nonl();
  cbreak();
  noecho();
  init_pair(Color::FOOD, COLOR_GREEN, COLOR_BLACK);
  init_pair(Color::PACMAN, COLOR_YELLOW, COLOR_BLACK);
  init_pair(Color::GHOST, COLOR_RED, COLOR_BLACK);
  init_pair(Color::NORMAL, COLOR_WHITE, COLOR_BLACK);
}

void Game::renderMap() {
  for (int y = 0; y < MAP.size(); y++) {
    const std::string_view line = MAP.at(y);
    for (int x = 0; x < line.size(); x++) {
      const char *character = &line.at(x);
      mvprintw(y, x, character);
    }
  }
  refresh();
}

void Game::printScore(Pacman *pacman, int x, int y) {
  const string output = "Current score: " + std::to_string(pacman->getScore());
  attron(COLOR_PAIR(Color::NORMAL));
  mvprintw(y, x, output.c_str());
  refresh();
}

void Game::endGame(Pacman *pacman) {
  clear();
  Game::printScore(pacman, 0, 0);
  refresh();
  usleep(SECOND * 5);
  endwin();
  exit(0);
}

void Game::onCollision(Entity::CollisionType collision, Pacman *pacman,
                       Entity::movementX directionX,
                       Entity::movementY directionY) {
  if (collision == Entity::NONE) {
    if (directionX != Entity::STAY_X)
      pacman->moveX(directionX);
    if (directionY != Entity::STAY_Y)
      pacman->moveY(directionY);
  }
  if (collision == Entity::FOOD) {
    pacman->addPoint();
  }
  if (collision == Entity::GHOST) {
    if (directionX != Entity::STAY_X)
      pacman->moveX(directionX);
    if (directionY != Entity::STAY_Y)
      pacman->moveY(directionY);
    usleep(SECOND);
    endGame(pacman);
  }
}

void Game::GetInput(Pacman *pacman, const vector<Entity *> &entities) {
  int ch;
  static int chtmp;

  ch = getch();

  // Buffer input
  if (ch == ERR)
    ch = chtmp;
  chtmp = ch;

  switch (ch) {
  case KEY_UP: {
    auto collision =
        pacman->checkForCollision(entities, Entity::STAY_X, Entity::UP);
    Game::onCollision(collision, pacman, Entity::STAY_X, Entity::UP);
    break;
  }

  case KEY_DOWN: {
    auto collision =
        pacman->checkForCollision(entities, Entity::STAY_X, Entity::DOWN);
    Game::onCollision(collision, pacman, Entity::STAY_X, Entity::DOWN);
    break;
  }
  case KEY_LEFT: {
    auto collision =
        pacman->checkForCollision(entities, Entity::LEFT, Entity::STAY_Y);
    Game::onCollision(collision, pacman, Entity::LEFT);
    break;
  }
  case KEY_RIGHT: {
    auto collision =
        pacman->checkForCollision(entities, Entity::RIGHT, Entity::STAY_Y);
    Game::onCollision(collision, pacman, Entity::RIGHT);
    break;
  }
  }
}

[[noreturn]] void Game::start() {
  auto pacman = new Pacman(6, 10);
  auto ghost1 = new Ghost(6, 4);
  auto ghost2 = new Ghost(17, 1);
  auto ghost3 = new Ghost(16, 13);
  auto food = new Food();
  vector<Entity *> entities = {food, ghost1, ghost2, ghost3};
  pacman->render();
  while (true) {
    for (auto entity : entities) {
      if (strcmp(entity->toName(), "Ghost") == 0) {
        auto tmpGhost = (Ghost *)entity;
        tmpGhost->move(pacman);
      }
      entity->render();
    }
    Game::GetInput(pacman, entities);
    printScore(pacman);
    refresh();
    usleep(FPS);
  }
}