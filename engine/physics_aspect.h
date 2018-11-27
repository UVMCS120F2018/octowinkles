//
// Created by Ethan Nerney on 11/2/18.
//

#ifndef SPACE_STUFF_PHYSICSASPECT_H
#define SPACE_STUFF_PHYSICSASPECT_H


#include "structs.h"
#include "entity.h"
#include "collider.h"

#include <stdlib.h>
#include <experimental/optional>
#include <vector>


class PhysicsAspect: public Entity {
    typedef std::experimental::optional<PhysicsAspect> optPhys;
private:
    Entity *e;
    int mass;

public:
    static int indices;
    static std::vector<PhysicsAspect*> worldPhysicsAspects;

    bool debug = false;

    int index;

    position2D::Vector2D velocity;

    position2D::Vector2D kineticEnergy;
    position2D::Vector2D momentum;

    Circle collider;


    PhysicsAspect(Entity *entity);
    PhysicsAspect(Entity *entity, int m);
    PhysicsAspect(Entity *entity, int m, Circle c);

    void addForce(position2D::Vector2D v);

    void setVelocity(position2D::Vector2D v);

    void update() override;
    void draw() override;

    void elasticCollision(PhysicsAspect &p);
    void inelasticCollison(PhysicsAspect &p);

    void checkForCollision();

    void onCollisionDetected(PhysicsAspect &p);

    void setEnergyAndMomentum();

    friend bool operator ==(PhysicsAspect &lhs, PhysicsAspect &rhs);
};

#endif //SPACE_STUFF_PHYSICSASPECT_H
