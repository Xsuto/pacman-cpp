//
// Created by Michał Sutowicz on 01/02/2022.
//

#ifndef PACMAN_FOOD_H
#define PACMAN_FOOD_H
#include "Entity.h"
#include "vector"
using std::vector;
class Food : public Entity {
private:
public:
  int currentIndex = 0;
  inline static const vector<vector<int>> spawnPoints = {
      {11, 10}, {16, 16}, {6, 6}, {4, 1}, {16, 1}, {4, 15}, {16, 16}};

  explicit Food(const char *icon = "$")
      : Entity(spawnPoints.at(0).at(0), spawnPoints.at(0).at(1), icon){};

  void render() override;

  [[nodiscard]] const char *toName() const override { return "Food"; }

  void respawn() override;
};

#endif // PACMAN_FOOD_H
