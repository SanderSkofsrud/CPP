#include <iostream>
#include <fstream>
#include <cstdlib>

void analyzeTemperatureIntervals(const double temperatures[], int numTemperatures);

int main() {
    const int numTemperatures = 5;  // Number of temperature entries to be processed
    const char fileName[] = "../temperatures.txt";  // File containing temperature data

    std::ifstream inputFile(fileName);  // Open the file for reading

    if (!inputFile) {
        std::cerr << "An error has occurred while attempting to open the specified file." << std::endl;
        exit(EXIT_FAILURE);  // Exit the program if the file cannot be opened
    }

    double temperatures[numTemperatures];  // Array to store the temperatures from the file
    int currentIndex = 0;

    // Read temperatures from the file line by line
    while (currentIndex < numTemperatures && inputFile >> temperatures[currentIndex]) {
        currentIndex++;
    }

    inputFile.close();  // Close the file after reading

    analyzeTemperatureIntervals(temperatures, numTemperatures);  // Analyze and display temperature intervals

    return 0;
}

// Function to analyze temperature intervals (same as before)
void analyzeTemperatureIntervals(const double temperatures[], int numTemperatures) {
    int intervalCounts[3] = {};  // Array to count temperatures in different intervals:
                                 // index 0: count of temperatures < 10
                                 // index 1: count of temperatures between 10 and 20
                                 // index 2: count of temperatures > 20

    for (int i = 0; i < numTemperatures; i++) {
        std::cout << "Temperature " << i + 1 << ": " << temperatures[i] << "\n";

        if (temperatures[i] < 10) {
            intervalCounts[0]++;
        } else if (temperatures[i] <= 20) {
            intervalCounts[1]++;
        } else {
            intervalCounts[2]++;
        }
    }

    std::cout << "\nNumber of temperatures under 10: " << intervalCounts[0] << "\n";
    std::cout << "Number of temperatures between 10 and 20: " << intervalCounts[1] << "\n";
    std::cout << "Number of temperatures over 20: " << intervalCounts[2] << std::endl;
}
