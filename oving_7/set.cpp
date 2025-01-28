#include "set.hpp"
#include <algorithm>

// Constructor for an empty set
Set::Set() {}

// Constructor with initialization
Set::Set(const std::vector<int> &elements) {
    for (int value : elements) {
        *this += value;
    }
}

// Add a new number to the set
Set &Set::operator+=(int value) {
    if (!contains(value)) {
        elements.push_back(value);
    }
    return *this;
}

// Find the union of two sets
Set Set::operator+(const Set &other) const {
    Set result = *this;
    for (int value : other.elements) {
        result += value;
    }
    return result;
}

// Assign one set to another
Set &Set::operator=(const Set &other) {
    if (this != &other) {
        elements = other.elements;
    }
    return *this;
}

// Helper function to check if an element exists
bool Set::contains(int value) const {
    return std::find(elements.begin(), elements.end(), value) != elements.end();
}

// Access elements
int &Set::operator[](size_t index) {
    return elements[index];
}

// Get size of the set
size_t Set::size() const {
    return elements.size();
}

// Output operator
std::ostream &operator<<(std::ostream &out, const Set &set) {
    out << "{ ";
    for (size_t i = 0; i < set.elements.size(); ++i) {
        out << set.elements[i];
        if (i != set.elements.size() - 1) {
            out << ", ";
        }
    }
    out << " }";
    return out;
}
