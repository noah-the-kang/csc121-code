#include <iostream>
#include <ctime>


int main() {
    int sides, rolls;
    char ch1;
    std::cout << "\t\tWelcome to the Dice Statistics Program!"
     << std::endl;
    std::cout << "Enter your dice roll: ";
    std::cin >> rolls >> ch1 >> sides;
    std::cout << "Rolls: " << rolls << ", Sides: " << sides << std::endl;
    std::cout << "When rolling " << rolls << ch1 << sides
     << " (" << rolls << " " << sides << "-sided dice), the results are:"
    << std::endl;

    int* rollArr = new int[rolls];
    for (int i = 0; i < rolls; ++i) {
        srand(time(NULL));
        int roll = (std::rand() % sides) + 1; // Generate a random roll
        rollArr[i] = roll;
    }

    // min, max, and average calculations
    int min = rolls;
    int max = rolls*sides;
    double avg = (max+min) / 2.0;

    std::cout << "\tMinimum roll: " << min << std::endl;
    std::cout << "\tMaximum roll: " << max << std::endl;
    std::cout << "\tAverage roll: " << avg << std:: endl;

    return 0;
}
