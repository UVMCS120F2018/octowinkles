//
// Created by Zach Bernstein on 12/3/18.
//

#ifndef OCTOWINKLE_PERIWINKLE_H
#define OCTOWINKLE_PERIWINKLE_H

#include "engine/circle.h"




class Periwinkle : public Circle {


private:
    int radius;
public:
    Periwinkle(int radius, position2D::Vector2D center, colorGraphics::RGBColor color);

    void draw() override;

    void update() override;

};

class Smilewinkle : public Periwinkle{
public:
    Smilewinkle(int radius, position2D::Vector2D center, colorGraphics::RGBColor color);
    void draw() override;
};

class Frownwinkle : public Periwinkle{
public:
    Frownwinkle(int radius, position2D::Vector2D center, colorGraphics::RGBColor color);
    void draw() override;
};
#endif //OCTOWINKLE_PERIWINKLE_H
