//
// Created by Michał Sutowicz on 01/02/2022.
//
#pragma once
#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include "Pacman.h"

namespace Game {
void init();
void renderMap();
void printScore(Pacman *pacman, int x = 0,
                int y = static_cast<int>(MAP.size()) + 2);
void endGame(Pacman *pacman);
void onCollision(Entity::CollisionType collision, Pacman *pacman,
                 Entity::movementX directionX = Entity::STAY_X,
                 Entity::movementY directionY = Entity::STAY_Y);
void GetInput(Pacman *pacman, const std::vector<Entity *> &entities);
[[noreturn]] void start();
};     // namespace Game
#endif // PACMAN_GAME_H
