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

    // min, max, and average calculations
    int min = rolls;
    int max = rolls*sides;
    double avg = (max+min) / 2.0;

    std::cout << "\tMinimum roll: " << min << std::endl;
    std::cout << "\tMaximum roll: " << max << std::endl;
    std::cout << "\tAverage roll: " << avg << std:: endl;

    srand(time(NULL));
    int roll = (std::rand() % sides) + 1; // Generate a random roll

    std::cout << "A typical roll of " << rolls << ch1 << sides
     << " might end up with a value of "<< roll;

    return 0;
}
