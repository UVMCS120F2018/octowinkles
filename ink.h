//
// Created by Cecily Page on 11/27/18.
//
#include "engine/entity.h"
#include "engine/circle.h"
#include <vector>
using namespace std;
#ifndef OCTOWINKLE_INK_H
#define OCTOWINKLE_INK_H


class Ink : public Entity {

public:
    position2D::Vector2D position;
    colorGraphics::RGBColor inkColor;
    vector<Circle> splatters;

    Ink(position2D::Vector2D point);
    void setPosition(position2D::Vector2D v);
    void draw();
    void update();
    void translate(position2D::Vector2D v);

};


#endif //OCTOWINKLE_INK_H
