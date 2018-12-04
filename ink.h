//
// Created by Cecily Page on 11/27/18.
//

#ifndef OCTOWINKLE_INK_H
#define OCTOWINKLE_INK_H


#include "engine/entity.h"
#include "engine/circle.h"
#include <vector>
using namespace std;



class Ink : public Entity {

private:
    colorGraphics::RGBColor inkColor;
    vector<Circle> splatters;
    position2D::Vector2D position;

public:

    Ink(position2D::Vector2D point);
    void setPosition(position2D::Vector2D v);
    void draw() override;
    void update() override;
    void translate(position2D::Vector2D v) override;
    bool isOverlapping(Circle &overlappingCircle);

};


#endif //OCTOWINKLE_INK_H
