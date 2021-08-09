#include "Employee.h"

using namespace std;

Employee::Employee()
{
   this->firstName = "";
   this->lastName = "";
   this->payRate = 0.0;
} 
   
Employee::Employee(string firstName, string lastName, double payRate)
{
   if (payRate < 0.0)
   {
      cout << "Pay rate must be > 0.0. Changing it minimum wage." << endl;
	  payRate = 7.25;
   }
   else if (payRate < 7.25)
	  payRate = 7.25;
	  
   this->firstName = firstName;
   this->lastName = lastName;
   this->payRate = payRate;
} 

void Employee::setFirstName(string firstName)
{
   this->firstName = firstName;
}

void Employee::setLastName(string lastName)
{
   this->lastName = lastName;
} 

string Employee::getFirstName()
{
   return firstName;
}

string Employee::getLastName()
{
   return lastName;
} 

void Employee::setPayRate(double payRate)
{
   if (payRate < 0.0)
   {
      cout << "Pay rate must be > 0.0. Changing it minimum wage." << endl;
	  this->payRate = 7.25;
   }
   else if (payRate < 7.25)
	  this->payRate = 7.25;
   else
	  this->payRate = payRate;
} 

double Employee::getPayRate()
{
   return payRate;
} 

double Employee::calcTaxes(double theGrossPay)
{
	double taxes;
	
    if (theGrossPay > 15000)
       taxes = theGrossPay * (36/100.0);
    else if (theGrossPay > 12000)
       taxes = theGrossPay * (31/100.0);
    else if (theGrossPay > 9000)
       taxes = theGrossPay * (28/100.0);
    else if (theGrossPay > 6500)
       taxes = theGrossPay * (22/100.0);
    else if (theGrossPay > 4500)
       taxes = theGrossPay * (15/100.0);
    else if (theGrossPay > 2500)
       taxes = theGrossPay * (10/100.0);
    else if (theGrossPay > 0)
       taxes = theGrossPay * 0;       
   
   return taxes;
}
