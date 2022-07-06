//
// Created by Michał Sutowicz on 01/02/2022.
//
#pragma once
#include "vector"

#ifndef PACMAN_ENTITY_H
#define PACMAN_ENTITY_H

class Entity {
public:
  Entity(int startx, int starty, const char *icon) {
    x = startx;
    y = starty;
    Icon = icon;
  };

  struct Position {
    int x;
    int y;
  };
  enum movementY { UP = -1, DOWN = 1, STAY_Y = 0 };
  enum movementX {
    LEFT = -1,
    RIGHT = 1,
    STAY_X = 0

  };
  enum CollisionType { WALL, GHOST, FOOD, PACMAN, NONE };

  [[nodiscard]] virtual const char *toName() const = 0;

  virtual void respawn(){};

  virtual void render(){};

  void moveX(movementX directionX);
  void moveY(movementY directionY);
  [[nodiscard]] CollisionType checkForCollision(std::vector<Entity *> entities,
                                                movementX directionX,
                                                movementY directionY) const;

  Position getPosition() { return {x, y}; };

protected:
  int x, y;
  const char *Icon;
};

#endif // PACMAN_ENTITY_H
