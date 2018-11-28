//
// Created by Ethan Nerney on 11/1/18.
//

#include <iostream>
#include "shape.h"

Shape2D::Shape2D(position2D::Vector2D center, colorGraphics::RGBColor col): Entity(center), shapeColor(col){}

void Shape2D::setColor(colorGraphics::RGBColor &col) {
    shapeColor = col;
}

void Shape2D::setCenter(position2D::Vector2D &center) {
    centerPoint = center;
}

colorGraphics::RGBColor Shape2D::getColor() {
    return shapeColor;
}