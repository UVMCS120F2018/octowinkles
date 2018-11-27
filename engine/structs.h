#ifndef SPACE_STUFF_STRUCTS_H
#define SPACE_STUFF_STRUCTS_H

//
// Created by Ethan Nerney on 11/1/18.
//

/*
 * This file declares the structs for RGBColor, RGBAColor, Vector2D, and Vector3D. It also declares several constants,
 * that are highly likely to be used frequently.
 */
#include <math.h>
#include <iostream>
#include "rand.h"

namespace colorGraphics {
    // RGB Color is a struct for a standard color
    struct RGBColor {
        double r;
        double g;
        double b;
        // RGB Constructor that takes doubles as the rgb values, for ease in graphics
        RGBColor(double red, double green, double blue) {
            r = red;
            g = green;
            b = blue;
        }

        // RGB Constructor that takes ints (0-255) as rgb values, and converts them to doubles
        RGBColor(int red, int green, int blue) {
            r = red / 255.;
            g = green / 255.;
            b = blue / 255.;
        }


        friend RGBColor operator !(RGBColor c) {
            return RGBColor(1 - c.r, 1 - c.g, 1 - c.b);
        }

        friend RGBColor operator +(RGBColor lhs, RGBColor rhs) {
            return RGBColor(lhs.r + rhs.r, lhs.g + rhs.g, lhs.b + rhs.b);
        }

    };

    // RGBA Color is a struct for a color with transparency
    struct RGBAColor {
        double r;
        double g;
        double b;
        double a;

        // RGBA Constructor that takes doubles for rgb and a double for the opacity
        RGBAColor(double red, double green, double blue, double alpha) {
            r = red;
            g = green;
            b = blue;
            a = alpha;
        }

        // RGBA Constructor that takes ints (0-255) for rgb and a double (0.0-1.0) for the opacity
        RGBAColor(int red, int green, int blue, double alpha) {
            r = red / 255.;
            g = green / 255.;
            b = blue / 255.;
            a = alpha;
        }
    };

    struct RGBGradient {
        RGBColor point1;
        RGBColor point2;

        // Constructor that takes the first and last colors in the gradient
        RGBGradient(RGBColor startPoint, RGBColor endPoint): point1(startPoint), point2(endPoint) {
        }

        RGBColor getColor() {
            RandNum r;
            double percent = r.getInt(100) / 100.0;

            return RGBColor(point1.r + (point2.r - point1.r) * percent, point1.g + (point2.g - point1.g) * percent, point1.b + (point2.b - point1.b) * percent);
        }
    };

    // Constants
    const RGBColor BLACK(0,0,0);
    const RGBColor RED(1.,0.,0.);
    const RGBColor ORANGE(255, 165, 0);
    const RGBColor YELLOW(255,255,0);
    const RGBColor BLUE(0., 0., 1.);
    const RGBColor GREEN(0., 1., 0.);
    const RGBColor WHITE(1.,1.,1.);
    const RGBColor GRAY(.3,.3,.3);


    const RGBGradient FIRE(RED, YELLOW);
    const RGBGradient WATER(BLUE, GRAY);
    const RGBGradient GRAYSCALE(BLACK, WHITE);
}

namespace position2D {
    // Vector2D is a struct that has an x value, a y value, and a rotation angle. It can be used for a point or a (physics)
    // vector for direction of motion
    struct Vector2D {
        double x;
        double y;
        double rotationAngle;

        // Constructor for an x and y position/direction with no angle of rotation
        Vector2D(double x, double y): Vector2D(x,y,0) {}

        // Constructor for an x and y position/direction with an angle of rotation
        Vector2D(double x, double y, double rot) {
            this->x = x;
            this->y = y;
            rotationAngle = fmod(rot, 360);
        }

        // Multiplying a vector by a scalar returns a vector with each aspect of the original vector being multiplied
        // by that scalar (m stands for multiple)
        friend Vector2D operator *(Vector2D v, double m) {
            return Vector2D(v.x * m, v.y * m, v.rotationAngle * m);
        }

        // Multiplying two vectors together returns a vector with each aspect being the product of the original two
        // vectors' aspects
        friend Vector2D operator *(Vector2D v, Vector2D v2) {
            return Vector2D(v.x * v2.x, v.y * v2.y, v.rotationAngle * v2.rotationAngle);
        }

        // Dividing a vector by a scalar returns a vector with each aspect of the original vector being divided by that
        // scalar (d stands for dividend)
        friend Vector2D operator /(Vector2D v, double d) {
            return Vector2D(v.x / d, v.y / d, v.rotationAngle / d);
        }

        // Adding two vectors together returns a vector with each aspect of the vector being the sum of the original
        // two vectors' aspects
        friend Vector2D operator +(Vector2D v1, Vector2D v2) {
            return Vector2D(v1.x + v2.x, v1.y + v2.y, v1.rotationAngle + v2.rotationAngle);
        }

        // Incrementing a vector by another vector is similar to adding them togeter
        Vector2D& operator +=(Vector2D v) {
            this->x += v.x;
            this->y += v.y;
            this->rotationAngle += v.rotationAngle;
            return *this;
        }

        // if two vectors have all the same values for their aspects they are equal
        friend bool operator ==(Vector2D lhs, Vector2D rhs) {
            return (lhs.x == rhs.x) and (lhs.y == rhs.y) and (lhs.rotationAngle == rhs.rotationAngle);
        }

        // difference of two vectors
        friend Vector2D operator-(Vector2D lhs, Vector2D rhs) {
            return Vector2D(lhs.x - rhs.x, lhs.y - rhs.y, lhs.rotationAngle - rhs.rotationAngle);
        }

        // negation of one vector
        friend Vector2D operator-(Vector2D v) {
            return Vector2D(-v.x, -v.y, -v.rotationAngle);
        }

        // output operator displaying the x, y, and angle values
        friend std::ostream& operator <<(std::ostream &outs, const Vector2D &rhs) {
            outs << "X: " << rhs.x << " Y: " << rhs.y << " A: " << rhs.rotationAngle;
            return outs;
        }



    };

    // Constants (multiply them by scalars if you want them to move more than one point/degree at a time)
    const Vector2D UP(0, -1);
    const Vector2D RIGHT(1, 0);
    const Vector2D DOWN(0,1);
    const Vector2D LEFT(-1, 0);

    const Vector2D ROTATE_RIGHT(0, 0, 1);
    const Vector2D ROTATE_LEFT(0, 0, -1);

    const Vector2D ZERO(0,0,0);

}

namespace position3D {
    // We're really not gonna touch this
    struct Vector3D {
        int x,y,z;
        int rotationX,rotationY,rotationZ;

        Vector3D(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;

            rotationX = 0;
            rotationY = 0;
            rotationZ = 0;
        }

        Vector3D(int x, int y, int z, int rotX, int rotY, int rotZ) {
            this->x = x;
            this->y = y;
            this->z = z;

            rotationX = rotX % 360;
            rotationY = rotY % 360;
            rotationZ = rotZ % 360;
        }

        friend Vector3D operator *(Vector3D &v, int m) {
            return Vector3D(v.x * m, v.y * m, v.z * m, v.rotationX * m, v.rotationY * m, v.rotationZ * m);
        }
    };

    const Vector3D UP(0, -1, 0);
    const Vector3D RIGHT(1, 0, 0);
    const Vector3D DOWN(0, 1, 0);
    const Vector3D LEFT(-1, 0, 0);
    const Vector3D BACKWARD(0,0,1);
    const Vector3D FORWARD(0,0,-1);
}

#endif //SPACE_STUFF_STRUCTS_H
