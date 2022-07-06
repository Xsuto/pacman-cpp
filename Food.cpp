//
// Created by Michał Sutowicz on 01/02/2022.
//

#include "Food.h"
#include "main.h"
#include "ncurses.h"
void Food::render() {
  attron(COLOR_PAIR(Color::FOOD));
  mvprintw(y, x, Icon);
  refresh();
}
void Food::respawn() {
  currentIndex += 1;
  mvprintw(y, x, " ");
  if (spawnPoints.size() == currentIndex)
    currentIndex = 0;
  x = spawnPoints.at(currentIndex).at(0);
  y = spawnPoints.at(currentIndex).at(1);
  render();
};
