#pragma once
#include <vector>
#include <iostream>

class Set {
private:
    std::vector<int> elements;

public:
    // Constructor for an empty set
    Set();

    // Constructor with initialization
    Set(const std::vector<int> &elements);

    // Add a new number to the set
    Set &operator+=(int value);

    // Find the union of two sets
    Set operator+(const Set &other) const;

    // Assign one set to another
    Set &operator=(const Set &other);

    // Print the set
    friend std::ostream &operator<<(std::ostream &out, const Set &set);

    // Helper function to check if an element exists
    bool contains(int value) const;

    // Access elements
    int &operator[](size_t index);

    // Get size of the set
    size_t size() const;
};
