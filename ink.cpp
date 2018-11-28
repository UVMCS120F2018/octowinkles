//
// Created by Cecily Page on 11/27/18.
//

#include "ink.h"

Ink ::Ink(position2D::Vector2D point): Entity(point), position(point.x, point.y), inkColor({0, 0, 0}) {
}

void Ink ::draw() {
    splatters.emplace_back(8, position, inkColor);
    for(int i = 0; i < 15; i++){
        int rad = rand() % 4;
        position2D::Vector2D edge = splatters[0].getPointOnEdge();
        splatters.emplace_back(rad, edge, inkColor);
    }
    for (auto &splatter : splatters) {
        splatter.draw();
    }
}


void Ink ::translate(position2D::Vector2D v) {
    double x = v.x;
    double y = v.y;
    for (auto &splatter : splatters) {
        splatter.setPosition();
    }
}