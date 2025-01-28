#include "fraction.hpp"
#include "set.hpp"
#include <iostream>
#include <vector>

void fractionMain() {
    Fraction a(10, 20);
    Fraction b(3, 4);
    Fraction c;
    c.set(5);
    Fraction d = a / b;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    b += a;
    ++c;
    d *= d;

    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    c = a + b - d * a;
    c = -c;

    std::cout << "c = " << c << std::endl;

    if (a + b != c + d)
        std::cout << "a + b != c + d" << std::endl;
    else
        std::cout << "a + b == c + d" << std::endl;

    while (b > a)
        b -= a;

    std::cout << "b = " << b << std::endl;

    // Testing fraction1 - 5 and 5 - fraction1
    Fraction result1 = b - 5;
    Fraction result2 = 5 - b;

    std::cout << "b - 5 = " << result1 << std::endl;
    std::cout << "5 - b = " << result2 << std::endl;

    // Testing the expression 5 - 3 - a - 7 - b
    Fraction testResult = 5 - 3 - a - 7 - b;
    std::cout << "5 - 3 - a - 7 - b = " << testResult << std::endl;
}

void setMain() {
    std::vector<int> vec1{1, 4, 3};
    std::vector<int> vec2{4, 7};

    Set set1(vec1);
    Set set2(vec2);
    Set set3 = set1 + set2;

    std::cout << "Set1: " << set1 << std::endl;
    std::cout << "Set2: " << set2 << std::endl;
    std::cout << "Union of Set1 and Set2: " << set3 << std::endl;

    set1 += 2;
    std::cout << "Set1 after adding 2: " << set1 << std::endl;

    set3 = set1;
    std::cout << "Set3 after assignment from Set1: " << set3 << std::endl;
}

int main() {
    std::cout << "\nExercise 1\n" << std::endl;
    fractionMain();

    std::cout << "\nExercise 2\n" << std::endl;
    setMain();

    return 0;
}
