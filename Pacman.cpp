//
// Created by Michał Sutowicz on 01/02/2022.
//

#include "Pacman.h"
#include "main.h"
#include "ncurses.h"
void Pacman::render() {
  attron(COLOR_PAIR(Color::PACMAN));
  mvprintw(y, x, Icon);
  refresh();
}
void Pacman::addPoint() { score += 1; }