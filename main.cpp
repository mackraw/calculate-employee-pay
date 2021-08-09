#include <iostream>
#include <iomanip>
#include <string>
#include "HourlyEmployee.h"

using namespace std;

void createEmployee();

int main ()
{
    createEmployee();
    return 0;
}

void createEmployee()
{
    string goOn = "yes";

    while (goOn.compare("no"))
    {
        string first = "";
        string last = "";
        double payrate = 0.0;

        cout << "\nEnter employee's first and last name: ";
        cin >> first >> last;
        cout << "Enter " << first << " " << last << "'s pay rate: ";
        cin >> payrate;
        
        HourlyEmployee emp(first, last, payrate);

        for (int i = 0; i < 4; i++)
        {
            double hrs = -1;
            while (hrs < 0 || hrs > 168)
            {
                cout << "Enter the number of hours " 
                     << emp.getFirstName() << " " << emp.getLastName() 
                     << " worked in week " << i + 1 << ": ";
                cin >> hrs;
                if (hrs < 0)
                    cout << "Please eneter a nonnegative value.\n";
                else if (hrs > 168)
                    cout << "There are only 168 hours in a week!\n";
            }

            emp.setTotalHoursWorked(hrs);
        }
        emp.displayInfo();

        cout << "\nCountinue? Enter 'no' to stop or any other character to continue: ";
        cin >> goOn;
    }

    cout << "Bye!\n";
}