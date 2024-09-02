#include <iostream>
using namespace std;

int find_sum(const int *table, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += table[i];
    }
    return sum;
}

int main() {
    int table[20];

    // Filling the table with values 1 to 20
    for (int i = 0; i < 20; i++) {
        table[i] = i + 1;
    }

    // Calculating sums
    int sum1 = find_sum(table, 10);       // Sum of first 10 numbers
    int sum2 = find_sum(table + 10, 5);   // Sum of next 5 numbers
    int sum3 = find_sum(table + 15, 5);   // Sum of last 5 numbers

    // Printing the sums
    cout << "Sum of the first 10 numbers: " << sum1 << endl;
    cout << "Sum of the next 5 numbers: " << sum2 << endl;
    cout << "Sum of the last 5 numbers: " << sum3 << endl;

    return 0;
}
