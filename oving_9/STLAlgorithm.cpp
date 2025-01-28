#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to print the contents of a vector
ostream &operator<<(ostream &out, const vector<int> &v) {
    for (const auto &e : v)
        out << e << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    vector<int> v2 = {2, 3, 12, 14, 24};

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    // Part a) Find the first element in v1 that is greater than 15
    auto it = find_if(v1.begin(), v1.end(), [](int value) {
        return value > 15;
    });

    if (it != v1.end()) {
        cout << "First element in v1 greater than 15 is: " << *it << endl;
        cout << "It is at index: " << distance(v1.begin(), it) << endl;
    } else {
        cout << "No element in v1 is greater than 15." << endl;
    }

    // Part b) Check if ranges are approximately equal
    auto approx_equal = [](int a, int b) {
        return abs(a - b) <= 2;
    };

    bool is_equal_5 = equal(
        v1.begin(), v1.begin() + 5,
        v2.begin(),
        approx_equal
    );

    bool is_equal_4 = equal(
        v1.begin(), v1.begin() + 4,
        v2.begin(),
        approx_equal
    );

    cout << "Are the first 5 elements of v1 approximately equal to v2? "
         << (is_equal_5 ? "Yes" : "No") << endl;

    cout << "Are the first 4 elements of v1 approximately equal to v2? "
         << (is_equal_4 ? "Yes" : "No") << endl;

    // Part c) Replace all odd numbers in v1 with 100
    vector<int> v1_modified;
    v1_modified.resize(v1.size());

    replace_copy_if(
        v1.begin(), v1.end(),
        v1_modified.begin(),
        [](int x) { return x % 2 != 0; },
        100
    );

    cout << "v1 after replacing odd numbers with 100: " << v1_modified << endl;

    return 0;
}
