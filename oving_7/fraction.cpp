#include "fraction.hpp"
#include <cmath>
#include <stdexcept>

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator_, int denominator_) {
    set(numerator_, denominator_);
}

void Fraction::set(int numerator_, int denominator_) {
    if (denominator_ == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    numerator = numerator_;
    denominator = denominator_;
    reduce();
}

Fraction Fraction::operator+(const Fraction &other) const {
    Fraction fraction = *this;
    fraction += other;
    return fraction;
}

Fraction &Fraction::operator+=(const Fraction &other) {
    numerator = numerator * other.denominator + denominator * other.numerator;
    denominator = denominator * other.denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator-(const Fraction &other) const {
    Fraction fraction = *this;
    fraction -= other;
    return fraction;
}

Fraction &Fraction::operator-=(const Fraction &other) {
    numerator = numerator * other.denominator - denominator * other.numerator;
    denominator = denominator * other.denominator;
    reduce();
    return *this;
}

// Member function for Fraction - int
Fraction Fraction::operator-(int integer) const {
    Fraction fraction;
    fraction.numerator = numerator - integer * denominator;
    fraction.denominator = denominator;
    fraction.reduce();
    return fraction;
}

// Non-member function for int - Fraction
Fraction operator-(int integer, const Fraction &fraction) {
    Fraction result;
    result.numerator = integer * fraction.denominator - fraction.numerator;
    result.denominator = fraction.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::operator*(const Fraction &other) const {
    Fraction fraction = *this;
    fraction *= other;
    return fraction;
}

Fraction &Fraction::operator*=(const Fraction &other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
    Fraction fraction = *this;
    fraction /= other;
    return fraction;
}

Fraction &Fraction::operator/=(const Fraction &other) {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    numerator *= other.denominator;
    denominator *= other.numerator;
    reduce();
    return *this;
}

Fraction Fraction::operator-() const {
    return Fraction(-numerator, denominator);
}

Fraction &Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction &Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction &Fraction::operator=(const Fraction &other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

bool Fraction::operator==(const Fraction &other) const {
    return compare(other) == 0;
}

bool Fraction::operator!=(const Fraction &other) const {
    return compare(other) != 0;
}

bool Fraction::operator<(const Fraction &other) const {
    return compare(other) < 0;
}

bool Fraction::operator>(const Fraction &other) const {
    return compare(other) > 0;
}

bool Fraction::operator<=(const Fraction &other) const {
    return compare(other) <= 0;
}

bool Fraction::operator>=(const Fraction &other) const {
    return compare(other) >= 0;
}

// Ensure that the denominator is always positive.
// Uses Euclid's algorithm to find the greatest common divisor.
void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int a = std::abs(numerator);
    int b = denominator;
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    numerator /= a;
    denominator /= a;
}

// Returns +1 if *this > other, 0 if they are equal, -1 otherwise
int Fraction::compare(const Fraction &other) const {
    int lhs = numerator * other.denominator;
    int rhs = other.numerator * denominator;
    if (lhs > rhs)
        return 1;
    else if (lhs == rhs)
        return 0;
    else
        return -1;
}

// Output operator
std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}
