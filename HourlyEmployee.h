#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "Employee.h"

class HourlyEmployee : public Employee
{
private:
    double totalHoursWorked;
    double totalRegularHours;
    double totalOvertime;

public:
    HourlyEmployee();
    HourlyEmployee(string, string, double);
    void setTotalHoursWorked(double);
    double getTotalHoursWorked();
    double getTotalRegularHours();
    double getTotalOvertime();
    double getRegularPay();
    double getOvertimePay();
    void displayInfo();
    string formatMoney(double);
};

#endif