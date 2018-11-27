//
// Created by Ethan Nerney on 11/1/18.
//

#include <math.h>
#include <iostream>
#include "circle.h"
#include "graphics_imports.h"
#include "rand.h"

Circle::Circle(int r, position2D::Vector2D center, colorGraphics::RGBColor color): Shape2D(center, color) {
    radius = r;
}

void Circle::setRadius(int r) {
    if (r > 0) {
        radius = r;
    }
}

int Circle::getRadius() {
    return radius;
}

double Circle::getPerimeter() {
    return 2 * M_PI * radius;
}

double Circle::getArea() {
    return M_PI * radius * radius;
}

void Circle::draw() {
    glBegin(GL_POLYGON);
    glColor3f(getColor().r, getColor().g, getColor().b);

    int r = getRadius();
    int num_segments = 50;
    int cx = getCenter().x, cy = getCenter().y;
    for (int i = 0, h = cx - r, k = cy; i < num_segments; i++) {


        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex
    }

    glEnd();
}

position2D::Vector2D Circle::getPointOnEdge() {
    RandNum r;

    float angle = r.getInt(360);
    float theta = angle * M_PI / 180;

    int x = cosf(theta) * radius + centerPoint.x;
    int y = sinf(theta) * radius + centerPoint.y;
    return position2D::Vector2D(x, y, angle);


}

position2D::Vector2D Circle::getPointOnEdge(int arcAngle) {
    RandNum r;

    float angle = r.getInt(arcAngle / -2, arcAngle / 2) + centerPoint.rotationAngle;
    float theta = angle * M_PI / 180;

    int x = cosf(theta) * radius + centerPoint.x;
    int y = sinf(theta) * radius + centerPoint.y;
    return position2D::Vector2D(x, y, angle);
}


bool Circle::doesIntersect(Circle &c) {
    double sqDistance = (centerPoint.x - c.getCenter().x) * (centerPoint.x - c.getCenter().x) + (centerPoint.y - c.getCenter().y) * (centerPoint.y - c.getCenter().y);
    double sqRad = (radius + c.getRadius()) * (radius + c.getRadius());

    return  sqDistance <= sqRad;
}


bool Circle::doesIntersect(Circle &c, position2D::Vector2D &intersection) {
    double sqDistance = (centerPoint.x - c.getCenter().x) * (centerPoint.x - c.getCenter().x) + (centerPoint.y - c.getCenter().y) * (centerPoint.y - c.getCenter().y);
    double sqRad = (radius + c.getRadius()) * (radius + c.getRadius());



    return  sqDistance <= sqRad;
}

//position2D::Vector2D Circle::getCenter() {
//    int cx = getCenter().x, cy = getCenter().y;
//    position2D::Vector2D center(cx, cy);
//    return center;
//}

