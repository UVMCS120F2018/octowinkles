//
// Created by mcdoy on 12/3/2018.
//
#include "engine/entity.h"
#include "engine/circle.h"
#include <vector>
using namespace std;

#ifndef OCTOWINKLE_HANK_H
#define OCTOWINKLE_HANK_H
class Hank: public Entity{
public:
    position2D::Vector2D position;
    colorGraphics::RGBColor eyeColor;
    colorGraphics::RGBColor hankColor;
    colorGraphics::RGBColor pupilColor;

    Hank(position2D::Vector2D point);
    void draw() override;
    void setPosition(position2D::Vector2D point);
    void moveRight(double dist);
    void moveLeft(double dist);

};

#endif //OCTOWINKLE_HANK_H
