//
// Created by Michał Sutowicz on 01/02/2022.
//

#include "Ghost.h"
#include "Entity.h"
#include "Game.h"
#include "ncurses.h"
#include "vector"
#include <unistd.h>
using std::vector;

void Ghost::render() {
  attron(COLOR_PAIR(Color::GHOST));
  mvprintw(y, x, Icon);
  refresh();
}
void Ghost::move(Pacman *pacman) {
  {

    mvprintw(y, x, " ");
    int x_or_y = getRandomNumberInRange();
    if (x_or_y < 1) {
      int newX = getRandomNumberInRange();
      if (newX <= -0.5) {
        auto collisionition =
            checkForCollision(vector<Entity *>{pacman}, LEFT, STAY_Y);
        onCollision(collisionition, pacman, LEFT);
      }
      if (newX >= 0.5) {
        auto collision =
            checkForCollision(vector<Entity *>{pacman}, RIGHT, STAY_Y);
        onCollision(collision, pacman, RIGHT);
      }
    } else {
      int newY = getRandomNumberInRange();
      if (newY <= -0.5) {
        auto collision =
            checkForCollision(vector<Entity *>{pacman}, STAY_X, DOWN);
        onCollision(collision, pacman, STAY_X, DOWN);
      }
      if (newY >= 0.5) {
        auto collision =
            checkForCollision(vector<Entity *>{pacman}, STAY_X, UP);
        onCollision(collision, pacman, STAY_X, UP);
      }
    }

    render();
    refresh();
  };
}
void Ghost::onCollision(Entity::CollisionType collision, Pacman *pacman,
                        Entity::movementX directionX,
                        Entity::movementY directionY) {
  if (collision == NONE) {
    if (directionX != STAY_X)
      moveX(directionX);
    if (directionY != STAY_Y)
      moveY(directionY);
  }
  if (collision == PACMAN) {
    if (directionX != STAY_X)
      moveX(directionX);
    if (directionY != STAY_Y)
      moveY(directionY);
    usleep(SECOND);
    Game::endGame(pacman);
  }
}