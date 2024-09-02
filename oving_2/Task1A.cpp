#include <iostream>
using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    // Printing the addresses and values
    cout << "Address of i: " << &i << ", Value of i: " << i << endl;
    cout << "Address of j: " << &j << ", Value of j: " << j << endl;
    cout << "Address of p: " << &p << ", Value pointed by p: " << *p << endl;
    cout << "Address of q: " << &q << ", Value pointed by q: " << *q << endl;

    return 0;
}
