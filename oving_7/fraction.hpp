#pragma once
#include <iostream>

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction();
    Fraction(int numerator, int denominator);

    void set(int numerator_, int denominator_ = 1);

    Fraction operator+(const Fraction &other) const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator-(int integer) const;
    Fraction operator*(const Fraction &other) const;
    Fraction operator/(const Fraction &other) const;
    Fraction operator-() const;

    Fraction &operator++(); // Pre-increment
    Fraction &operator--(); // Pre-decrement
    Fraction &operator+=(const Fraction &other);
    Fraction &operator-=(const Fraction &other);
    Fraction &operator*=(const Fraction &other);
    Fraction &operator/=(const Fraction &other);
    Fraction &operator=(const Fraction &other);

    bool operator==(const Fraction &other) const;
    bool operator!=(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;
    bool operator>=(const Fraction &other) const;
    bool operator<(const Fraction &other) const;
    bool operator>(const Fraction &other) const;

    // Friend function for int - Fraction
    friend Fraction operator-(int integer, const Fraction &fraction);

    // Friend function for output
    friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction);

private:
    void reduce();
    int compare(const Fraction &other) const;
};
