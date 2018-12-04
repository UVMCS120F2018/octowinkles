//
// Created by Zach Bernstein on 12/3/18.
//

#include "periwinkle.h"
#include "engine/graphics_imports.h"

Periwinkle::Periwinkle(int radius, position2D::Vector2D center, colorGraphics::RGBColor color)
: Circle(radius, center, color) {}

void Periwinkle::draw() {
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

    glBegin(GL_TRIANGLES);
    glColor3f(getColor().r, getColor().g, getColor().b);

    glVertex2f(cx - r, cy);
    glVertex2f(cx + r * cosf(2.f * 3.1415926f * 1.274f), cy - r * sinf(2.f * 3.1415926f * 1.274f));
    glVertex2f(cx - r - 10.f, cy - r - 2.f);

    glEnd();
}

void Periwinkle::update() {
    Entity::update();
}
