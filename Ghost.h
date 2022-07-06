//
// Created by Michał Sutowicz on 01/02/2022.
//
#pragma once
#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H
#include "Entity.h"
#include "Pacman.h"
#include "main.h"
#include "random"

class Ghost : public Entity {
public:
  Ghost(int startx, int starty, const char *icon = "@")
      : Entity(startx, starty, icon){};

  [[nodiscard]] const char *toName() const override { return "Ghost"; }

  void render() override;

  void onCollision(Entity::CollisionType collision, Pacman *pacman,
                   Entity::movementX directionX = STAY_X,
                   Entity::movementY directionY = STAY_Y);

  void move(Pacman *pacman);

  void respawn() override{};

private:
  static int getRandomNumberInRange(int a = -1, int b = 1) {
    static std::random_device randomDevice;
    static std::mt19937 generator(randomDevice());
    static std::uniform_int_distribution<> distribution(a, b);
    int direction = distribution(generator);
    return direction;
  };
};
#endif // PACMAN_GHOST_H
