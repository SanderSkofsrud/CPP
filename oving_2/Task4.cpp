#include <iostream>
using namespace std;

int main() {
    int a = 5;

    // References must be initialized when declared
    int &b = a;

    // Pointer declaration is correct, no change needed
    int *c;

    // c should point to an integer, so it can point to a
    c = &a;

    // Correct the operation: since a is an integer, the operation should be
    a = b + *c;

    // Cannot assign to a reference directly
    // &b = 2; // This is invalid, instead we should assign the value directly to b
    b = 2;

    return 0;
}
