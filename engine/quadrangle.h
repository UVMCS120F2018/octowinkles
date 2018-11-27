//
// Created by Ethan Nerney on 11/1/18.
//

#ifndef SPACE_STUFF_QUADRANGLE_H
#define SPACE_STUFF_QUADRANGLE_H


#include "structs.h"
#include "shape.h"

class Quadrangle: public Shape2D {
private:
    int side1;
    int side2;
public:
    Quadrangle(int s1, int s2, position2D::Vector2D p, colorGraphics::RGBColor c);

    void setSide1(int s1);
    void setSide2(int s2);

    int getSide1();
    int getSide2();

    double getArea() override;
    double getPerimeter() override;

    void draw() override;

};


#endif //SPACE_STUFF_QUADRANGLE_H
