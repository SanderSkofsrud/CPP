#include <iostream>
using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    // Modifying values through pointers
    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;

    // Printing the final values pointed by p and q
    cout << *p << " " << *q << endl;

    return 0;
}
