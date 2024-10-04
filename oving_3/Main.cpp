#include <iostream>
#include <string>

int main() {
    // Read three words from the user
    std::string word1, word2, word3;
    std::cout << "Enter three words: ";
    std::cin >> word1 >> word2 >> word3;

    // Concatenate the words into a sentence
    std::string sentence = word1 + " " + word2 + " " + word3 + ".";
    std::cout << "The sentence is: " << sentence << std::endl;

    // Print the length of each word and the sentence
    std::cout << "Length of word1: " << word1.length() << std::endl;
    std::cout << "Length of word2: " << word2.length() << std::endl;
    std::cout << "Length of word3: " << word3.length() << std::endl;
    std::cout << "Length of sentence: " << sentence.length() << std::endl;

    // Create a copy of the sentence
    std::string sentence_copy = sentence;

    // Replace characters at position 10-12 with 'x'
    if (sentence_copy.length() >= 13) {
        sentence_copy[10] = 'x';
        sentence_copy[11] = 'x';
        sentence_copy[12] = 'x';
    }

    std::cout << "Original sentence: " << sentence << std::endl;
    std::cout << "Modified sentence: " << sentence_copy << std::endl;

    // Extract the first five characters of the sentence
    std::string sentence_start = sentence.substr(0, 5);
    std::cout << "First five characters: " << sentence_start << std::endl;

    // Check if the sentence contains the word "Hello"
    bool contains_hello = sentence.find("Hello") != std::string::npos;
    std::cout << "Does the sentence contain 'Hello'? " << (contains_hello ? "Yes" : "No") << std::endl;

    // Count occurrences of "er" in the sentence
    std::string target = "er";
    size_t count = 0;
    size_t pos = sentence.find(target);
    while (pos != std::string::npos) {
        ++count;
        pos = sentence.find(target, pos + target.length());
    }
    std::cout << "Occurrences of 'er': " << count << std::endl;

    return 0;
}
