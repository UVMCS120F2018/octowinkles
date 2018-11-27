//
// Created by Ethan Nerney on 11/3/18.
//

#include <iostream>
#include "collider.h"
std::vector<CircleCollider> CircleCollider::allColliders;
CircleCollider::CircleCollider(Entity *e, position2D::Vector2D offset, int r): entity(e), Circle(r, e->getCenter() + offset, colorGraphics::GREEN) {}

void CircleCollider::update() {
    // check for collision enter
    for (CircleCollider &c: currentlyCollidingObjects) {
        if (!contains(c, collisions)) {
            collisions.push_back(c);
            onColliderEnter(c);
        }
    }

    // check for collision exit
    for (CircleCollider &c: collisions) {
        if (!contains(c, currentlyCollidingObjects)) {
            if (!colliding) {
                onColliderExit(c);
            }
            remove(c, collisions);
            colliding = true;
            break;
        } else {
            colliding = false;
        }
    }

}

void CircleCollider::draw() {}

void CircleCollider::onColliderEnter(CircleCollider &c) {
    //std::cout << "Collider Enter" << std::endl;
}

void CircleCollider::onColliderExit(CircleCollider &c) {
    std::cout << "Collision Detected" << std::endl;
}

void CircleCollider::setTag(std::string t) {
    colliderTag = t;
}

std::string CircleCollider::getTag() {
    return colliderTag;
}

bool operator ==(CircleCollider &c1, CircleCollider &c2) {
    return (c1.getTag() == c2.getTag()) and (c1.getCenter() == c2.getCenter());
}




template <typename T>
bool contains(T obj, std::vector<T> v) {
    for (T &o: v) {
        if (obj == o) {
            return true;
        }
    }
    return false;
}

template <typename T>
void remove(T obj, std::vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        if (obj == v.at(i)) {
            v.erase(v.begin() + i);
            return;
        }
    }
}