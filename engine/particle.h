//
// Created by Ethan Nerney on 11/2/18.
//

#ifndef SPACE_STUFF_PARTICLE_H
#define SPACE_STUFF_PARTICLE_H


#include "circle.h"

class Particle: public Circle {
private:
    position2D::Vector2D velocity;
    position2D::Vector2D startPoint;
    int lifeSpan;
    int increment = 0;

    float xMotion = 0;
    float yMotion = 0;


    float theta;

    int arcAngle;

    Circle &generator;
    bool hide = false;

public:
    bool canDraw = true;
    Particle(int size, position2D::Vector2D center, position2D::Vector2D velo, colorGraphics::RGBColor color, int life, Circle &g, int arcAngle);

    void update() override;

    void draw() override;

    std::string toString() override;
};


#endif //SPACE_STUFF_PARTICLE_H
