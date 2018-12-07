//
// Created by Cecily Page on 12/6/18.
//

#ifndef OCTOWINKLE_PLAYER_H
#define OCTOWINKLE_PLAYER_H

#include <string>

class Player {
private:
    int score;
    std::string name;

public:

    Player(int score, std::string name);

    int getScore() const;

    const std::string &getName() const;

    friend bool operator<(const Player &p1, const Player &p2);
    friend bool operator<=(const Player &p1, const Player &p2);
    friend bool operator>(const Player &p1, const Player &p2);
    friend bool operator>=(const Player &p1, const Player &p2);
    friend bool operator==(const Player &p1, const Player &p2);

};




#endif //OCTOWINKLE_PLAYER_H
