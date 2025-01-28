#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Template function to check if two values are equal
template <typename Type>
bool equal(Type a, Type b) {
    cout << "Using the template version." << endl;
    return a == b;
}

// Specialized function for double types
bool equal(double a, double b) {
    cout << "Using the double specialization." << endl;
    // Check if the absolute difference is less than 0.00001
    return fabs(a - b) < 0.00001;
}

int main() {
    int int1 = 10, int2 = 10;
    double double1 = 3.141592, double2 = 3.141593;

    // Set precision for outputting double values
    cout << fixed << setprecision(10);

    // Test with integer values
    if (equal(int1, int2))
        cout << int1 << " and " << int2 << " are equal." << endl;
    else
        cout << int1 << " and " << int2 << " are not equal." << endl;

    // Test with double values
    if (equal(double1, double2))
        cout << double1 << " and " << double2 << " are approximately equal." << endl;
    else
        cout << double1 << " and " << double2 << " are not equal." << endl;

    return 0;
}
