#include <iostream>
using namespace std;

int main() {
    double number;

    // Defining a pointer pointing to number
    double *ptr = &number;

    // Defining a reference to number
    double &ref = number;

    // Three ways to assign a value to number
    number = 10.5;
    *ptr = 20.5;
    ref = 30.5;

    // Output to verify the value
    cout << "Value of number: " << number << endl;

    return 0;
}
