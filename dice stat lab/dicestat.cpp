#include <iostream>
#include <ctime>


int main() {
    int sides, rolls;
    std::cout << "\t\tWelcome to the Dice Statistics Program!"
     << std::endl;
    std::cout << "Enter the number of sides on the die: ";
    std::cin >> sides;
    std::cout << "Enter the number of rolls to simulate: ";
    std::cin >> rolls;
    std::cout << "When rolling a " << sides << "-sided die "
     << rolls << " times, the results are:" << std::endl;

    int* rollArr = new int[rolls];
    for (int i = 0; i < rolls; ++i) {
        int roll = (std::rand() % sides) + 1; // Generate a random roll
        srand(time(NULL));
        rollArr[i] = roll;
    }

    // min, max, and average calculations
    int min = rollArr[0];
    int max = rollArr[0];
    double sum = 0.0;
    for (int i = 0; i < rolls; ++i) {
        if (rollArr[i] < min) {
            min = rollArr[i];
        }
        if (rollArr[i] > max) {
            max = rollArr[i];
        }
        sum += rollArr[i];
    }

    std::cout << "\tMinimum roll: " << min << std::endl;
    std::cout << "\tMaximum roll: " << max << std::endl;
    std::cout << "\tAverage roll: " << (sum / rolls) << std:: endl;

    return 0;
}
