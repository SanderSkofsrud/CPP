#include "Circle.h"
#include <iostream>

const double pi = 3.141592;

/**
 * Constructor that initializes the radius of the circle.
 * @param radius The radius of the circle.
 */
Circle::Circle(double radius): radius(radius) {}

/**
 * Returns the area of the circle.
 * @return Area of the circle.
 */
double Circle::get_area() const {
    return pi * radius * radius;
}

/**
 * Returns the circumference of the circle.
 * @return Circumference of the circle.
 */
double Circle::get_circumference() const {
    return 2.0 * pi * radius;
}

/**
 * Main function to test the Circle class.
 */
int main() {
    Circle circle(5);  // Create a circle with radius 5

    double area = circle.get_area();
    std::cout << "The area is: " << area << std::endl;

    double circumference = circle.get_circumference();
    std::cout << "The circumference is: " << circumference << std::endl;

    return 0;
}
