//
// Created by Ethan Nerney on 11/2/18.
//

#include <math.h>
#include <iostream>
#include "particle_system.h"

ParticleSystem::ParticleSystem(int particleNum, int generationRate,
                               int length, int arcAngle, int arcHeight, int partSize,
                               colorGraphics::RGBColor particleColor,
                               position2D::Vector2D centerPoint):
        Entity(centerPoint), generator(arcHeight, centerPoint, particleColor), partColor(particleColor, particleColor) {
    particles = particleNum;
    rate = generationRate;
    particleSize = partSize;
    this->length = length;
    this->arcAngle = arcAngle;



}

ParticleSystem::ParticleSystem(int particleNum, int generationRate, int length, int arcAngle, int arcHeight,
                               int partSize, colorGraphics::RGBGradient particleGradient,
                               position2D::Vector2D centerPoint):
        Entity(centerPoint), generator(arcHeight, centerPoint, particleGradient.getColor()), partColor(particleGradient) {
    particles = particleNum;
    rate = generationRate;
    particleSize = partSize;
    this->length = length;
    this->arcAngle = arcAngle;
}

void ParticleSystem::draw() {

        for (Particle &p: particleEntities) {
            p.draw();
        }

}
void ParticleSystem::update() {

    // sets the generator position to the center of the particle system
    generator.setPosition(getCenter());
    // updates every particle
    for (Particle &p: particleEntities) {
        p.update();
    }

    // if the the increment hasn't gotten up to the rate limit then don't generate another particle
    if (increment < rate) {
        increment++;
    // if
    } else if (particles > 0 and canDraw) {
        increment = 0;
        position2D::Vector2D v = generator.getPointOnEdge(arcAngle);
        int x = cosf(v.rotationAngle * M_PI / 180) * 2;
        int y = sinf(v.rotationAngle * M_PI / 180) * 2;
        particleEntities.emplace_back(Particle(particleSize, v, position2D::Vector2D(0,0,v.rotationAngle), partColor.getColor(), length, generator, arcAngle));
        particles--;
    }
}

void ParticleSystem::translate(position2D::Vector2D v) {
    Entity::translate(v);
    generator.translate(v);
    for (Particle &p: particleEntities) {
        p.translate(v);
    }
}

void ParticleSystem::start() {
    canDraw = true;
    for (Particle &p: particleEntities) {
        p.canDraw = true;
    }
}

void ParticleSystem::stop() {
    canDraw = false;
    for (Particle &p: particleEntities) {
        p.canDraw = false;
    }
}