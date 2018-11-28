//
// Created by Ethan Nerney on 11/1/18.
//

#include "entity.h"

Entity::Entity(position2D::Vector2D point): centerPoint(point) {}

// the center point gets incremented by the vector translated
void Entity::translate(position2D::Vector2D v) {
    centerPoint += v;
}

// the center point gets set to the vector passed through
void Entity::setPosition(position2D::Vector2D v) {
    centerPoint = v;
}

position2D::Vector2D Entity::getCenter() {
    return centerPoint;
}

void Entity::update() {}

std::string Entity::toString() {
    return "Entity";
}

