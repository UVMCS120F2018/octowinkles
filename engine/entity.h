//
// Created by Ethan Nerney on 11/1/18.
//

#ifndef SPACE_STUFF_ENTITY_H
#define SPACE_STUFF_ENTITY_H

#include <stdlib.h>
#include <vector>

#include "structs.h"



class Entity {
protected:
    position2D::Vector2D centerPoint;

public:
    // Constructor that takes a center point for the entity
    Entity(position2D::Vector2D point);

    // Sets the position of the entity to any point instantly
    void setPosition(position2D::Vector2D v);

    // moves the entity from it's current point over by v amount
    virtual void translate(position2D::Vector2D v);

    // returns the center point of the entity as a vector2d
    position2D::Vector2D getCenter();

    // gets called every frame
    virtual void update();

    // abstract method for drawing
    virtual void draw() = 0;

    virtual std::string toString();

};


#endif //SPACE_STUFF_ENTITY_H
