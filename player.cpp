//
// Created by Cecily Page on 12/6/18.
//

#include "player.h"


Player::Player(int score,  std::string name) : score(score), name(name) {}


int Player::getScore() const {
    return score;
}

const std::string &Player::getName() const {
    return name;
}


bool operator<(Player player1, Player player2){
    return player1.getScore() >= player2.getScore();
}




