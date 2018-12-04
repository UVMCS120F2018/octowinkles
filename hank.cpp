//
// Created by mcdoy on 12/3/2018.
//

#include "hank.h"

Hank::Hank(position2D::Vector2D point):Entity(point), position(point.x, point.y), hankColor({1, 0, 0}), pupilColor({0,0,0}), eyeColor({1,1,1}) {

}
void Hank::draw(){
    Circle mainCircle(50, {480, 670, 0}, hankColor);
    mainCircle.draw();

    Circle LeftEyeOne(10, {490, 645, 0}, eyeColor);
    Circle RightEyeTwo(10, {470, 645, 0}, eyeColor);

    LeftEyeOne.draw();
    RightEyeTwo.draw();

    Circle pupilLeft(5, {485,640, 0}, pupilColor);
    Circle pupilRight(5, {465,640, 0}, pupilColor);

    pupilLeft.draw();
    pupilRight.draw();
    }
void Hank::setPosition(position2D::Vector2D point) {

}
void Hank::move(){

}