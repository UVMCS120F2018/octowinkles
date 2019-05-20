//
// Created by Ethan Nerney on 11/2/18.
//

#include <iostream>
#include "physics_aspect.h"
#include "particle_system.h"

//typedef std::experimental::optional<PhysicsAspect> optPhys;

std::vector<PhysicsAspect*> PhysicsAspect::worldPhysicsAspects;
int PhysicsAspect::indices = 0;

PhysicsAspect::PhysicsAspect(Entity *entity):PhysicsAspect(entity, 1) {}
PhysicsAspect::PhysicsAspect(Entity *entity, int m): PhysicsAspect(entity, m, Circle(10, entity->getCenter(), colorGraphics::GREEN)){}
PhysicsAspect::PhysicsAspect(Entity *entity, int m, Circle c): Entity(entity->getCenter()), collider(c), e(entity), velocity(position2D::Vector2D(0,0)), kineticEnergy(position2D::ZERO), momentum(position2D::ZERO)  {
    mass = m;
    PhysicsAspect::worldPhysicsAspects.push_back(this);

    index = PhysicsAspect::indices;
    PhysicsAspect::indices++;
    e->setPosition(position2D::Vector2D(e->getCenter().x,e->getCenter().y));
    //std::cout <<"index: "<< index << " indices: " << indices << std::endl;
}

void PhysicsAspect::addForce(position2D::Vector2D v) {
    velocity += (v / mass);
}

void PhysicsAspect::setVelocity(position2D::Vector2D v) {
    velocity = v;
}

void PhysicsAspect::update() {
    e->translate(velocity);
    setPosition(e->getCenter());
    collider.setPosition(getCenter());

    checkForCollision();


    setEnergyAndMomentum();
}

void PhysicsAspect::draw() {
    if (debug) {
        collider.draw();
    }
}

void PhysicsAspect::elasticCollision(PhysicsAspect &p) {
    position2D::Vector2D fullMomentum = (velocity * mass) + (p.velocity * p.mass);
    p.addForce(fullMomentum);
    addForce(fullMomentum * -1);
}
void PhysicsAspect::inelasticCollison(PhysicsAspect &p) {
    position2D::Vector2D fullMomentum = (velocity * mass) + (p.velocity * p.mass);
    position2D::Vector2D vFinal = fullMomentum / (mass + p.mass);
    setVelocity(vFinal);
    p.setVelocity(vFinal);
}

void PhysicsAspect::checkForCollision() {
    //std::cout << "checking" << std::endl;
    for (int i = 0; i < PhysicsAspect::worldPhysicsAspects.size(); i++) {
        if (i!=index) {
            PhysicsAspect &p = *PhysicsAspect::worldPhysicsAspects.at(i);
            position2D::Vector2D intersection(0,0,0);
            if (collider.doesIntersect(p.collider, intersection)) {
                onCollisionDetected(p);
                //ParticleSystem s2(500, 1, 20, 360, 20, 3, colorGraphics::RGBColor(250,50,50), intersection);
                //Entity::allEntities.push_back(&s2);
            }
        }
    }

}

void PhysicsAspect::onCollisionDetected(PhysicsAspect &p) {
    elasticCollision(p);

}


void PhysicsAspect::setEnergyAndMomentum() {
    momentum = velocity * mass;
    kineticEnergy = momentum * velocity;
}

bool operator ==(PhysicsAspect &lhs, PhysicsAspect &rhs) {
    return (lhs.index == rhs.index);
}