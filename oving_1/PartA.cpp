#include <iostream>

// Function declaration for finding temperature intervals
void findTemperatureIntervals(int numTemperatures);

int main() {
    const int numTemperatures = 5;  // Number of temperature inputs
    findTemperatureIntervals(numTemperatures);

    return 0;
}

// Function to find temperature intervals
void findTemperatureIntervals(int numTemperatures) {
    std::cout << "Enter " << numTemperatures << " temperatures.\n";

    double temperatures[numTemperatures];  // Array to store the input temperatures
    int intervalCounts[3] = {};  // Array to count temperatures in different intervals:
    // index 0: count of temperatures < 10
    // index 1: count of temperatures between 10 and 20
    // index 2: count of temperatures > 20

    // Loop to input temperatures and categorize them into intervals
    for(int i = 0; i < numTemperatures; i++) {
        std::cout << "Temperature " << i + 1 << ": ";
        std::cin >> temperatures[i];

        // Categorize the temperature into one of the intervals
        if(temperatures[i] < 10) {
            intervalCounts[0]++;
        } else if (temperatures[i] <= 20) {
            intervalCounts[1]++;
        } else {
            intervalCounts[2]++;
        }
    }

    // Output the results
    std::cout << "\nNumber of temperatures under 10: " << intervalCounts[0] << "\n";
    std::cout << "Number of temperatures between 10 and 20: " << intervalCounts[1] << "\n";
    std::cout << "Number of temperatures over 20: " << intervalCounts[2] << std::endl;
}
