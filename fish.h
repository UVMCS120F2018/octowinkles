//
// Created by Cecily Page on 12/9/18.
//

#ifndef OCTOWINKLE_FISH_H
#define OCTOWINKLE_FISH_H

#include "engine/circle.h"


class Fish: public Circle{

public:
    Fish(int radius, position2D::Vector2D center, colorGraphics::RGBColor color);
    void draw() override;
    void update() override;
};


#endif //OCTOWINKLE_FISH_H
