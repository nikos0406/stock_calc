#include <cmath>
#include "stock_calc.h"

double return_on_investment(double starting_amount,
                            double interest_rate,
                            int    years_invested,
                            double monthly_payment)
{
    // Convert annual percentage to a decimal, then to monthly interest rate
    double monthly_interest = (interest_rate / 100.0) / 12.0;
    // Total number of months
    int months = 12 * years_invested;

    // 1) Future value of the initial lump sum
    double lump_sum_future = starting_amount * std::pow(1.0 + monthly_interest, months);

    // 2) Future value of the annuity (monthly contributions)
    double annuity_future = 0.0;
    if (monthly_interest != 0.0) {
        annuity_future = monthly_payment *
                         (std::pow(1.0 + monthly_interest, months) - 1.0) /
                         monthly_interest;
    } else {
        // If interest rate is 0, it's just payment * months
        annuity_future = monthly_payment * months;
    }

    // Total
    return lump_sum_future + annuity_future;
}