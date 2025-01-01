#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include "stock_calc.h"

void clearScreen() {
    system("clear");
}

int main() {
    bool runAgain = false;

    do {
        clearScreen();

        std::cout << "\033[1;32m"
                  << "                   Welcome to the Compound Interest Calculator!\n"
                  << "\033[0m"
                  << std::endl;

        double starting_amount = 0.0;
        double interest_rate   = 0.0;
        int    years_invested  = 0;
        double monthly_payment = 0.0;

        std::cout << "\033[1;36m" << "Enter your starting amount (e.g. 2000): " << "\033[0m";
        std::cin  >> starting_amount;
        while (std::cin.fail() || starting_amount < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive number: ";
            std::cin >> starting_amount;
        }

        std::cout << "\033[1;36m" << "Enter the annual interest rate (in %, e.g. 8): " << "\033[0m";
        std::cin  >> interest_rate;
        while (std::cin.fail() || interest_rate < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive number: ";
            std::cin >> interest_rate;
        }

        std::cout << "\033[1;36m" << "Enter the number of years you'll invest (e.g. 20): " << "\033[0m";
        std::cin  >> years_invested;
        while (std::cin.fail() || years_invested < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a non-negative integer: ";
            std::cin >> years_invested;
        }

        std::cout << "\033[1;36m" << "Enter your monthly contribution (e.g. 100): " << "\033[0m";
        std::cin  >> monthly_payment;
        while (std::cin.fail() || monthly_payment < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a non-negative number: ";
            std::cin >> monthly_payment;
        }

        double future_value = return_on_investment(
            starting_amount,
            interest_rate,
            years_invested,
            monthly_payment
        );

        std::cout << "\n\033[1;33m"
                  << "=============================================================\n"
                  << "  Estimated Future Value : $"
                  << std::fixed << std::setprecision(2) 
                  << future_value
                  << "\n============================================================="
                  << "\033[0m" << std::endl;

        std::cout << "\nWould you like to perform another calculation? (y/n): ";
        char answer;
        std::cin >> answer;

        if (std::cin.fail() || (answer != 'y' && answer != 'Y')) {
            runAgain = false;
        } else {
            runAgain = true;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (runAgain);

    std::cout << "\nGoodbye!\n\n";
    return 0;
}