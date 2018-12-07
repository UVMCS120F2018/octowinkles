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


bool operator<(const Player &player1, const Player &player2){
    return player1.getScore() > player2.getScore();
}

bool operator<=(const Player &p1, const Player &p2) {
    return p1.getScore()>=p2.getScore();
}

bool operator>(const Player &p1, const Player &p2) {
    return p1.getScore()<p2.getScore();
}

bool operator>=(const Player &p1, const Player &p2) {
    return p1.getScore()<=p2.getScore();
}

bool operator==(const Player &p1, const Player &p2) {
    return p1.getScore() == p2.getScore();
}





