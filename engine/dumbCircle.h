//
// Created by Hunter Jensen on 12/6/18.
//

#ifndef SPACE_STUFF_CIRCLE_H
#define SPACE_STUFF_CIRCLE_H


#include "shape.h"

class DumbCircle: public Shape2D {
private:
    int radius;
public:
    // takes a radius, centerpoint, and color
    DumbCircle(int r, position2D::Vector2D center, colorGraphics::RGBColor color);

    void setRadius(int r);

    int getRadius();

    double getArea() override;
    double getPerimeter() override;

    virtual void draw() override = 0;

//    position2D::Vector2D getCenter();


    // This returns a random point on the edge of the circle for use in
    position2D::Vector2D getPointOnEdge();
    position2D::Vector2D getPointOnEdge(int arcAngle);

    bool doesIntersect(DumbCircle &c);

    bool doesIntersect(DumbCircle &c, position2D::Vector2D &intersection);
};


#endif //SPACE_STUFF_CIRCLE_H
