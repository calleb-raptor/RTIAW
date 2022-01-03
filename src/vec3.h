#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

/*
 * the vec3 class has dual purpose - 1. it is to be used for the direction of the ray, i.e. x, y, and z coordinates
 * and 2. to be used for color (R, G, B)
 */

using std::sqrt;

class vec3
{
public:
    // initialise a an array of size 3 (e)
    float e[3];

public:
    // default constructor - constructs a vector of 0s
    vec3() : e{0, 0, 0} {}
    // parametised constructor - constructs a vector of the arguments input
    vec3(float e0, float e1, float e2) : e{e0, e1, e2} {}

    // getters for elements in the vector
    float x() const { return e[0]; }
    float y() const { return e[1]; }
    float z() const { return e[2]; }

    // operator function to return the negatives of all elements in the vector as a new vector object
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    // operator function to return an element in the vector based on index i
    float operator[](int i) const { return e[i]; }
    // operator function to return a reference to an element in the vector based on index i
    float &operator[](int i) { return e[i]; }

    // Operator function to add one vector to the current vector - returns a pointer to the current object
    vec3 &operator+=(const vec3 &v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }
    // operator function to multiply a vector to the current vector - returns a pointer to the current object
    vec3 &operator*=(const float t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }
    // operator function to divide vector by a float - utilises *= operator above to multiply each element by 1/float parameter
    vec3 &operator/=(const float t)
    {
        return *this *= 1 / t;
    }

    // return the length of the vector
    float length() const
    {
        return sqrt(length_squared());
    }
    // return the squared length of the vector
    float length_squared() const
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
};

// type aliases
// TODO: brush up on this syntax
using point3 = vec3;
using color = vec3;

// define utility functions

inline std::ostream &operator<<(std::ostream &out, const vec3 &v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[0] + v.e[1], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[0] - v.e[1], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[0] * v.e[1], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(float t, const vec3 &v)
{
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3 &v, float t)
{
    return t * v;
}

inline vec3 operator/(vec3 v, float t)
{
    return (1 / t) * v;
}

inline double dot(const vec3 &u, const vec3 &v)
{
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1], u.e[2] * v.e[0] - u.e[0] * v.e[2], u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v)
{
    return v / v.length();
}

#endif // VEC3_H