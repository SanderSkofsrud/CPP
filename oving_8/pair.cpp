#include <iostream>
using namespace std;

// Class template for Pair
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    // Constructor that initializes the pair elements
    Pair(T1 first, T2 second) : first(first), second(second) {}

    // Operator+ to add two pairs element-wise
    Pair operator+(const Pair& other) const {
        // We assume that operator+ is defined for T1 and T2
        return Pair(first + other.first, second + other.second);
    }

    // Operator> to compare pairs based on the sum of their elements
    bool operator>(const Pair& other) const {
        // We assume that operator+ is defined for T1 and T2
        // and that the result can be compared using operator>
        auto sum_this = first + second;
        auto sum_other = other.first + other.second;
        return sum_this > sum_other;
    }
};

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);

    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 is greater" << endl;
    else
        cout << "p2 is greater" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;

    return 0;
}
