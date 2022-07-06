//
// Created by Michał Sutowicz on 01/02/2022.
//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include "Entity.h"
#include "main.h"
class Pacman : public Entity {

public:
  [[nodiscard]] int getScore() const { return score; }

  void addPoint();

  void render() override;

  [[nodiscard]] const char *toName() const override { return "Pacman"; }
  Pacman(int startx, int starty, const char *icon = "*")
      : Entity(startx, starty, icon) {}

private:
  int score = 0;
};

#endif // PACMAN_PACMAN_H
