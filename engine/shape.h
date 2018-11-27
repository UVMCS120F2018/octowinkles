//
// Created by Ethan Nerney on 11/1/18.
//

#ifndef GRAPHICS_STARTER_SHAPE_H
#define GRAPHICS_STARTER_SHAPE_H

#include <vector>
#include "structs.h"
#include "entity.h"

class Shape2D: public Entity {
private:
    colorGraphics::RGBColor shapeColor;
public:
    // Takes center point and color, center gets sent to the superclass, color gets stored in shape
    Shape2D(position2D::Vector2D center, colorGraphics::RGBColor col);

    // redundant method, does the same as setPosition
    // TODO: Refactor code that uses setCenter so we can use just setPosition instead
    void setCenter(position2D::Vector2D &center);

    // Sets the color of the shape
    void setColor(colorGraphics::RGBColor &col);

    // returns the area of the shape
    virtual double getArea() = 0;

    // returns the perimeter of the shape
    virtual double getPerimeter() = 0;

    // returns the RGBColor assigned to the shape
    colorGraphics::RGBColor getColor();

    //virtual bool doesIntersect(Circle &c);
};


#endif //GRAPHICS_STARTER_SHAPE_H
