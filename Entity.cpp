//
// Created by Michał Sutowicz on 01/02/2022.
//

#include "Entity.h"
#include "main.h"
#include "ncurses.h"

Entity::CollisionType Entity::checkForCollision(std::vector<Entity *> entities,
                                                movementX directionX,
                                                movementY directionY) const {
  if (MAP.at(y + directionY).at(x + directionX) == *"#")
    return WALL;
  for (auto &entity : entities) {

    if (entity->getPosition().x == x + directionX &&
        entity->getPosition().y == y + directionY) {
      if (strcmp(entity->toName(), "Ghost") == 0)
        return GHOST;
      if (strcmp(entity->toName(), "Pacman") == 0)
        return PACMAN;
      if (strcmp(entity->toName(), "Food") == 0) {
        entity->respawn();
        return FOOD;
      }
    }
  }
  return NONE;
};
void Entity::moveX(movementX directionX) {
  mvprintw(y, x, " ");
  x += directionX;
  render();
  refresh();
};
void Entity::moveY(movementY directionY) {
  mvprintw(y, x, " ");
  y += directionY;
  render();
  refresh();
}