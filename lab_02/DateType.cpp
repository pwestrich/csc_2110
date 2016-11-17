// File DateType.cpp  contains the implementation of class DateType
#include "DateType.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

// Number of days in each month
static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,
                            31, 30, 31};	

// Names of the months
static string conversionTable[] = {"Error", "January", "February", 
    "March", "April", "May", "June", "July", "August", "September",
    "October", "November", "December"};

void DateType::Initialize (int newMonth, int newDay, int newYear)
// Post: If newMonth, newDay and newYear represent a valid date,
//       year is set to newYear;
//       month is set to newMonth;
//       day is set to newDay;
//       otherwise a string exception is thrown, stating the
//       first incorrect parameter.
{
     
     if (newYear < 1900)
          throw string("Invalid year. Exiting...");
     
     else
          year = newYear;
     
     if ((newMonth >= 13) || (newMonth <= 0))
          throw string("Invalid month. Exiting...");
              
     else
          month = newMonth;
     
     if ((newDay > daysInMonth[newMonth]) || (newDay <= 0))
          throw string("Invalid day. Exiting...");
               
     else
          day = newDay;
     
}

int DateType::GetMonth() const
// Accessor function for data member month.
{
   return month;
}

string DateType::GetMonthAsString() const
// Returns data member as a string
{
     
     return conversionTable[month];
     
}

int DateType::GetYear() const
// Accessor function for data member year.
{
   return year;
}

int DateType::GetDay() const
// Accessor function for data member day.
{
   return day;
}

bool DateType::leapYear(int year) const
//
// This function will check if the current year is a leap year or not.
// Returns a bool stating this.
//
{
     return (((year % 100 == 0) && !(year % 400 == 0)) || !(year % 4 == 0));
     
}

DateType DateType::Adjust(int daysAway) const
// Pre:  Self has been initialized
// Post: Function value = newDate daysAway from self
{
     
     //Initialize variables
     int newDay = day +daysAway;
     int newMonth = month;
     int newYear = year;
     int daysInThisMonth = 0;
     bool finished = false;
     DateType returnDate;
     
     while (!finished){
          
          daysInThisMonth = daysInMonth[newMonth]; //Find current # of days in current month
          
          if (newMonth == 2){ //Check February
               
               if (DateType::leapYear(newYear)){
                    
                    daysInThisMonth++;
                    
               }
               
          }
          
          if (newDay <= daysInThisMonth){
               
               finished = true;
               
          }
          
          else {
               
               newDay = newDay - daysInThisMonth;
               newMonth = (newMonth % 12) + 1;
               if (newMonth == 1){
                    
                    newYear++;
                    
               }
               
          }
          
     }
          
     returnDate.Initialize(newMonth, newDay, newYear);
     return returnDate;
     
}

