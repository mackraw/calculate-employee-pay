#include "HourlyEmployee.h"
#include <iomanip>

HourlyEmployee::HourlyEmployee() : HourlyEmployee("", "", 0)
{
}


HourlyEmployee::HourlyEmployee(string first, string last, double payrate) : Employee(first, last, payrate)
{
    totalHoursWorked = 0;
    totalRegularHours = 0;
    totalOvertime = 0;
}

void HourlyEmployee::setTotalHoursWorked(double hoursWorked)
{
    if (hoursWorked <= 40)
    {
        totalHoursWorked += hoursWorked;
        totalRegularHours += hoursWorked;
    }
    else if (hoursWorked > 40)
    {
        totalHoursWorked += hoursWorked;
        totalRegularHours += 40;
        totalOvertime += (hoursWorked - 40);
    }
}

double HourlyEmployee::getTotalHoursWorked()
{
    return totalHoursWorked;
}


double HourlyEmployee::getTotalRegularHours()
{
    return totalRegularHours;
}


double HourlyEmployee::getTotalOvertime()
{
    return totalOvertime;
}


double HourlyEmployee::getRegularPay()
{
    return getPayRate() * getTotalRegularHours();
}


double HourlyEmployee::getOvertimePay()
{
    return getPayRate() * 1.5 * getTotalOvertime();
}


void HourlyEmployee::displayInfo()
{
    double grossPay = getRegularPay() + getOvertimePay();
    double taxes = calcTaxes(grossPay);
    double netPay = grossPay - taxes;

    cout << fixed << setprecision(0) << left;

    cout << endl
         << setw(30) << "Name: " << getFirstName() << " " << getLastName() << endl
         << setw(30) << "Pay rate: " << formatMoney(getPayRate()) << endl
         << setw(30) << "Total regular hours worked: " << getTotalRegularHours() << endl
         << setw(30) << "Total overtime hours worked: " << getTotalOvertime() << endl
         << setw(30) << "Total hours worked: " << getTotalHoursWorked() << endl
         << setw(30) << "Monthly Regular Pay: " << formatMoney(getRegularPay()) << endl
         << setw(30) << "Monthly overtime pay: " << formatMoney(getOvertimePay()) << endl
         << setw(30) << "Monthly gross pay: " << formatMoney(grossPay) << endl
         << setw(30) << "Monthly taxes: " << formatMoney(taxes) << endl
         << setw(30) << "Monthly net pay: " << formatMoney(netPay) << endl;
    
}


string HourlyEmployee::formatMoney(double amount)
{
    string strAmount = to_string(amount);
    int positionOfDot = strAmount.find('.');

    while (positionOfDot > 3)
    {
        positionOfDot -= 3;
        strAmount.insert(positionOfDot, ",");
    }
    strAmount.insert(0, "$");

    int pd = strAmount.find('.');
    string final = strAmount.substr(0, pd + 3);

    return final;
}