//
// Created by Ethan Nerney on 11/1/18.
//

#include "quadrangle.h"
#include "graphics_imports.h"
#include <vector>
#include <math.h>

Quadrangle::Quadrangle(int s1, int s2, position2D::Vector2D p, colorGraphics::RGBColor c): Shape2D(p, c) {
    side1 = s1;
    side2 = s2;
}

double Quadrangle::getArea() {
    return side1 * side2;
}

double Quadrangle::getPerimeter() {
    return 2 * (side1 + side2);
}

void Quadrangle::draw() {
    glBegin(GL_POLYGON);
    glColor3f(getColor().r, getColor().g, getColor().b);

    double theta = getCenter().rotationAngle * 3.14 / 180.;

    std::vector<int> xCoords = {-(side1 / 2), (side1 / 2), (side1 / 2), -(side1 / 2)};

    std::vector<int> yCoords = {-(side2 / 2), -(side2 / 2), (side2 / 2), (side2 / 2)};

    for (int i = 0; i < 4; i ++) {
        int x = (xCoords.at(i) * cosf(theta)) - (yCoords.at(i) * sinf(theta));
        int y = (xCoords.at(i) * sinf(theta)) + (yCoords.at(i) * cosf(theta));

        glVertex2i(x + getCenter().x, y + getCenter().y);

    }


    glEnd();
}

int Quadrangle::getSide1() {
    return side1;
}

int Quadrangle::getSide2() {
    return side2;
}

void Quadrangle::setSide1(int s1) {
    side1 = s1;
}

void Quadrangle::setSide2(int s2) {
    side2 = s2;
}

