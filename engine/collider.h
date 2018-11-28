//
// Created by Ethan Nerney on 11/3/18.
//

#ifndef SPACE_STUFF_COLLIDER_H
#define SPACE_STUFF_COLLIDER_H

#include <string>
#include <experimental/optional>
#include "entity.h"
#include "structs.h"
#include "circle.h"

typedef std::experimental::optional<Entity*> optEnt;
class CircleCollider: public Circle{
private:
    std::string colliderTag;
    Entity *entity;

public:
    bool colliding;

    static std::vector<CircleCollider> allColliders;

    std::vector<CircleCollider> collisions;
    std::vector<CircleCollider> currentlyCollidingObjects;


    CircleCollider(Entity *e, position2D::Vector2D offset, int r);

    void update() override;
    void draw() override;

    void setTag(std::string t);
    std::string getTag();

    virtual void onColliderEnter(CircleCollider &c);
    virtual void onColliderExit(CircleCollider &c);

    friend bool operator ==(CircleCollider &c1, CircleCollider &c2);

};

template <typename T>
bool contains(T obj, std::vector<T> v);

template <typename T>
void remove(T obj, std::vector<T> v);


#endif //SPACE_STUFF_COLLIDER_H
