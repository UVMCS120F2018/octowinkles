//
// Created by Ethan Nerney on 11/2/18.
//

#include <math.h>
#include "particle.h"

Particle::Particle(int size, position2D::Vector2D center, position2D::Vector2D velo, colorGraphics::RGBColor color, int life, Circle &g, int arcAngle): Circle(size, center, color), velocity(velo), startPoint(center), generator(g) {
    lifeSpan = life;
    theta = velo.rotationAngle * 3.14 /180;
    this->arcAngle = arcAngle;
}

void Particle::update() {


    if (increment < lifeSpan) {
        increment++;

        xMotion += cosf(theta);
        yMotion += sinf(theta);

        translate(position2D::Vector2D(xMotion, yMotion));

        xMotion = fmod(xMotion, 1);
        yMotion = fmod(yMotion, 1);


    } else {
        if (canDraw) {
            hide = false;
        } else {
            hide = true;
        }

        increment = 0;
        position2D::Vector2D velo = generator.getPointOnEdge(arcAngle);
        setPosition(velo);
        theta = velo.rotationAngle * 3.14 / 180;
    }
}

void Particle::draw() {
    if (!hide) {
        Circle::draw();
    }
}

std::string Particle::toString() {
    return "particle";
}