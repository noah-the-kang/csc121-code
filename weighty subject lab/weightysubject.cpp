#include <iostream>
#include <limits>
#include <cmath>

int main() {
    const double OUNCES_IN_POUND = 16.0;
    std::cout << "\n\t\tWelcome to the Ounce Conversion Program!!!"
     << std::endl;

    double ounces;
    std::cout << "How many ounces do you have? ";
    std::cout << "Enter the number of ounces: ";
    std::cin >> ounces;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    double pounds = floorf(ounces / OUNCES_IN_POUND);
    double ounces_remainder = ounces - (pounds * OUNCES_IN_POUND);
    double pounds_total = ounces / OUNCES_IN_POUND;
    std::cout << "\n\t\t" << ounces << " oz. is equivalent to " << pounds
     << " lbs. and " << ounces_remainder << " oz. (" << pounds_total
      << " lbs.)." << std::endl;
    std::cout << "\n\t\tThank you for using the OCP!!" << std::endl;
    std::cout << "\n\t\tHave a great day!" << std::endl;
    return 0;
}
