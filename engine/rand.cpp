//
// Created by Ethan Nerney on 11/2/18.
//

#include <cstdlib>
#include <ctime>
#include "rand.h"

int RandNum::getInt(int bounds) {
    return rand() % bounds;
}

int RandNum::getInt(int start, int end) {
    return rand() % (end - start) + start;
}