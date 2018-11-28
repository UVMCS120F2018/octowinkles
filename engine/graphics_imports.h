//
// Created by Ethan Nerney on 11/1/18.
//

#ifndef SPACE_STUFF_GRAPHICSIMPORTS_H
#define SPACE_STUFF_GRAPHICSIMPORTS_H
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif //SPACE_STUFF_GRAPHICSIMPORTS_H
