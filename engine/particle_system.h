//
// Created by Ethan Nerney on 11/2/18.
//

#ifndef SPACE_STUFF_PARTICLESYSTEM_H
#define SPACE_STUFF_PARTICLESYSTEM_H


#include <vector>
#include "entity.h"
#include "circle.h"
#include "particle.h"

class ParticleSystem: public Entity {
private:
    int particles;
    int particleSize;
    int rate;
    int increment;
    int length;
    int arcAngle;

    bool canDraw = true;

    Circle generator;

    std::vector<Particle> particleEntities;

    //colorGraphics::RGBColor partColor;
    colorGraphics::RGBGradient partColor;
public:
    /* takes the number of particles to generate, the rate of generation, the lifespan of the particle, the angle
     * on the circle that the particles can generate, the radius of the generation circle, the radius of the particles,
     * the color that the particles will be, and the center point of the particle system
     */
    ParticleSystem(int particleNum, int generationRate, int length, int arcAngle, int arcHeight, int partSize,
                   colorGraphics::RGBColor particleColor, position2D::Vector2D centerPoint);

    /* takes everything the other constructor does, but instead of an RGBColor it takes a gradient, which determines
     * what colors the particles have a random chance of spawning with
     */
    ParticleSystem(int particleNum, int generationRate, int length, int arcAngle, int arcHeight, int partSize,
                   colorGraphics::RGBGradient particleGradient, position2D::Vector2D centerPoint);

    void draw() override;
    void update() override;

    void translate(position2D::Vector2D v) override;

    void start();
    void stop();

};


#endif //SPACE_STUFF_PARTICLESYSTEM_H
