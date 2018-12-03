//
// Created by Zach Bernstein on 12/3/18.
//

#include "periwinkle.h"

Periwinkle::Periwinkle(int radius, position2D::Vector2D center, colorGraphics::RGBColor color)
: Circle(radius, center, color) {}

void Periwinkle::draw() {
    Circle::draw();
}

void Periwinkle::update() {
    Entity::update();
}


