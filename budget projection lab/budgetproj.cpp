#include <iostream>
#include <cmath>

int main() {
    double allotment, spending;
    char ch1;

    std::cout << "What was your budget allotment last year? ";
    std::cin >> ch1 >> allotment;

    std::cout << "Fine, and how much did you spend last year? ";
    std::cin >> ch1 >> spending;

    std::cout << "\n\n";
    
    double percentage = floor(spending/allotment * 100);
    if (percentage > 100){
        std::cout << "This overspending will bankrupt the company!"
        << std::endl;
    } else if (percentage < 100){
        std::cout << 
        "Thanks to you, this company will be solvent for years to come!"
        << std::endl;
    } else {
        std::cout << "Way to keep your eye on the ball, Johnson!"
        << std::endl;
    }
    std::cout << "Last year you used up about " << percentage
    << "% of your budget." << std::endl;

    double nextBudget = floor(spending/100) * 100 + 100;
    std::cout << "Your budget for next year is $"
    << nextBudget << "." << std::endl;

    return 0;
}
