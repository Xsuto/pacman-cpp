//
// Created by Michał Sutowicz on 01/02/2022.
//
#pragma once
#include "string_view"
#include "vector"
#ifndef PACMAN_MAIN_H
#define PACMAN_MAIN_H
#define SECOND 1000000
#define FPS SECOND / 10
const std::vector<std::string_view> MAP = {
    "####################", "#        #         #", "# ## ### # ### ##  #",
    "# ## ### # ### ##  #", "#        #         #", "#   #    #    #    #",
    "#   #         #    #", "# ################ #", "# ################ #",
    "# ################ #", "#   #    #    #    #", "#   #  # # #  #    #",
    "#   #  # # #  #    #", "#                  #", "# ## ### # ### ##  #",
    "# ## ### # ### ##  #", "#                  #", "####################",
};
namespace Color {
enum Color { PACMAN = 1, FOOD = 2, GHOST = 3, NORMAL = 4 };
}
#endif // PACMAN_MAIN_H
