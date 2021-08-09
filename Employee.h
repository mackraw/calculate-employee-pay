#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

// The Class Employee
class Employee
{
private:
   
   string firstName;
   string lastName;
   double payRate;
	  
public:
   Employee();

   Employee(string firstName, string lastName, double payRate);

   virtual ~Employee() {}; 
   
   void setFirstName(string);
   void setLastName(string);
   void setPayRate(double);
   
   string getFirstName();
   string getLastName();
   double getPayRate();
   
   double calcTaxes(double);
   
};

#endif
