//
// Created by mcdoy on 12/3/2018.
//

#include "hank.h"

Hank::Hank(position2D::Vector2D point):Entity(point), position(point.x, point.y), hankColor({1., 0., 0.}), pupilColor({0.,0.,0.}), eyeColor({1.,1.,1.}) {

}
void Hank::draw(){
    double centX = position.x;
    double centY = position.y;
//    Circle mainCircle(50, {480, 670, 0}, hankColor);
    Circle mainCircle(50, position, hankColor);
    mainCircle.draw();

//    Circle LeftEyeOne(10, {490, 645, 0}, eyeColor);
    Circle LeftEyeOne(10, {centX+10, centY-25, 0}, eyeColor);
//    Circle RightEyeTwo(10, {470, 645, 0}, eyeColor);
    Circle RightEyeTwo(10, {centX-10, centY-25, 0}, eyeColor);

    LeftEyeOne.draw();
    RightEyeTwo.draw();

//    Circle pupilLeft(5, {485,640, 0}, pupilColor);
    Circle pupilLeft(5, {centX+5,centY-30, 0}, pupilColor);
//    Circle pupilRight(5, {465,640, 0}, pupilColor);
    Circle pupilRight(5, {centX-15,centY-30, 0}, pupilColor);

    pupilLeft.draw();
    pupilRight.draw();
}

void Hank::moveRight(double dist){
    if(position.x<910){
        position = {position.x+dist, position.y, position.rotationAngle};
    }

}

void Hank::moveLeft(double dist){
    if(position.x>50){
        position = {position.x-dist, position.y, position.rotationAngle};
    }

}

void Hank::setPosition(position2D::Vector2D v) {
    Entity::setPosition(v);
    position = {v.x, v.y, v.rotationAngle};
}
