#pragma once
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

/**
 * Class representing a geometric circle.
 */
class Circle {
public:
    /**
     * Constructor that initializes the circle with a given radius.
     * @param radius The radius of the circle.
     */
    Circle(double radius);

    /**
     * Returns the area of the circle.
     * @return Area of the circle.
     */
    double get_area() const;

    /**
     * Returns the circumference of the circle.
     * @return Circumference of the circle.
     */
    double get_circumference() const;

private:
    double radius;  // Radius of the circle
};

#endif
