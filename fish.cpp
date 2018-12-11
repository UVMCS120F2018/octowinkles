//
// Created by Cecily Page on 12/9/18.
//

#include "fish.h"
#include "engine/graphics_imports.h"

Fish::Fish(int radius, position2D::Vector2D center, colorGraphics::RGBColor color):
Circle(radius, center, color) {}

void Fish::update() {
    Entity::update();
}

void Fish::draw() {
    glBegin(GL_POLYGON);
    glColor3f(getColor().r, getColor().g, getColor().b);
//    glColor3f(getColor().r, getColor().g, getColor().b);
    int cx = getCenter().x, cy = getCenter().y;
    int r = getRadius();
    Circle body = Circle(getRadius(), getCenter(),getColor());
    Circle eye = Circle(5, {getCenter().x+12, getCenter().y -12,0}, {1.,1.,1.});
    Circle puple = Circle(2, {getCenter().x+12, getCenter().y -12,0}, {0.,0.,0.});
    body.draw();
    eye.draw();
    puple.draw();

    glEnd();


    // Tail
    glBegin(GL_TRIANGLES);
    glColor3f(getColor().r, getColor().g, getColor().b);
    glVertex2f(cx - r/2, cy);
    glVertex2f(cx - 1.5*r, cy-r);
    glVertex2f(cx - 1.5*r, cy+r);
    glEnd();

}