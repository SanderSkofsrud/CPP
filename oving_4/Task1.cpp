#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> vec{1.0, 2.0, 3.0, 4.0, 5.0};

    // Using front() and back()
    std::cout << "Front element: " << vec.front() << std::endl;
    std::cout << "Back element: " << vec.back() << std::endl;

    // Using emplace() to insert after the first element
    vec.emplace(vec.begin() + 1, 8.0);

    // Displaying front() after emplace
    std::cout << "First element after emplace: " << vec.front() << std::endl;

    // Printing the vector
    std::cout << "Vector elements: ";
    for (const auto &elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Using find() to search for a value
    auto it = std::find(vec.begin(), vec.end(), 6.0); // Searching for value 6

    if (it != vec.end()) {
        std::cout << "Value found: " << *it << std::endl;
    } else {
        std::cout << "Value 6 not found in the vector." << std::endl;
    }

    return 0;
}
