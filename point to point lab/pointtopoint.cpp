#include <iostream>
#include <cmath>

int main() {
    // Declare variables for the coordinates of the two points
    double x1, y1, x2, y2;
    char ch1, ch2, ch3;

    // Input the coordinates of the first point
    std::cout << "Enter the coordinates of the first point (x1 y1): ";
    std::cin >> ch1 >>  x1 >> ch2 >> y1 >> ch3;

    if (ch1 == '(' && ch2 == ',' && ch3 == ')') {
        // Input the coordinates of the second point
        std::cout << "Enter the coordinates of the second point (x2 y2): ";
        std::cin >> ch1 >> x2 >> ch2 >> y2 >> ch3;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (ch1 == '(' && ch2 == ',' && ch3 == ')') {
            // Calculate the midpoint
            double mid_x = (x1 + x2) / 2;
            double mid_y = (y1 + y2) / 2;

            // Output the result
            std::cout << "The midpoint between the points (" << x1 << ", "
             << y1 << ") and (" << x2 << ", " << y2 << ") is: (" << mid_x
             << ", " << mid_y << ")" << std::endl;
        } else {
            std::cout << "Invalid input format. Please enter coordinates"
            << " in the format (x, y)." << std::endl;
        }
    } else {
        std::cout << "Invalid input format. Please enter coordinates in"
        << " the format (x, y)." << std::endl;
    }
    return 0;
}
