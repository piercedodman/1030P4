/*
  *  Resources.h
  *                                                
  *  COSC 1030 Fall 2024
  *  Project #4
  *
  *  Due on: NOV 13, 2024
  *  Author: Dodman  rpd62                           
  * 
  *
  *  In accordance with the class policies and Georgetown's
  *  Honor Code, I certify that, with the exception of the 
  *  class resources and those items noted below, I have neither
  *  given nor received any assistance on this project. 
  *
  *  References not otherwise commented within the program source code.
  *  Note that you should not mention any help from the TAs, the professor, 
  *  or any code taken from the class textbooks.
  *
  */
 
 
 #ifndef __COSC1030_FALL2024_P3_RESOURCES_H__
 #define __COSC1030_FALL2024_P3_RESOURCES_H__
 
 
 
 //#define DEBUG_FILE_OPENING = 1
 //#define DEBUG_DATE
 
 
 
 #include <iostream>
 #include <iomanip>
 #include <exception>
 #include <stdexcept>
 #include <sstream>
 #include <fstream>
 #include <string>
 
 #include "Exceptions.h"
 
 using std::invalid_argument;
 using std::cout;
 using std::endl;
 using std::string;
 
 
 const int MAX_LINES = 10;
 
 // use for array indexes (can improve readability)
 enum MONTH_LIST {__NOT_USED_MONTH__, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
 
 enum HOUR_LIST {__NOT_USED_HOUR__, H01, H02, H03, H04, H05, H06, H07, H08, H09, H10, H11, H12,
                                    H13, H14, H15, H16, H17, H18, H19, H20, H21, H22, H23, H24 };
 // use minimum values as defaults unless otherwise specified
 
 // this array stores max day value for month number corresponding to array index
 const int MAX_DD[] =  { -1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 const int MIN_DD = 1;
 
 const int MIN_YYYY = 1492;   // minimum year 
 const int MAX_YYYY = 2192;   // maximum year 
 
 const int MIN_MM = 1;   // minimum month 
 const int MAX_MM = 12;  // maximum month 
 
 const int DEFAULT_YY = MIN_YYYY;  // default year value 
 const int DEFAULT_MM = MIN_MM;    // default month value 
 const int DEFAULT_DD = MIN_DD;    // default day value 
 
 
 const int MIN_HOUR = 0;           // minimum hour 
 const int MAX_HOUR = 24;          // 24:00 is valid for midnight, 00:00 would also be valid
 const int DEFAULT_H = MAX_HOUR;   // default hour 
 
 // maximum minute allowed for each hour 
 // could be useful (maybe not)
 // can use with the enum HOUR_LIST or index into the array with any valid int hour value 
 const int MAX_M_H[] = {-1,59,59,59,59,59,59, 59,59,59,59,59,59
                          ,59,59,59,59,59,59, 59,59,59,59,59, 0 };
 
 const int MIN_MINUTE = 0;    // minimum minute 
 const int MAX_MINUTE = 59;   // maximum minute 
 const int DEFAULT_M = MIN_MINUTE;     // default minute 
 
 
 std::string readDoubleQuotedString( std::istream& in ); // required
 std::string trimSpaces( std::string s ); // optional
 
 // complete implementation code given, may be useful (maybe not)
 void parseFullPathAndFileName( string valueToParse, 
                                string& path, string& fName, string& fNameAndExtension ); 
 
 
 /****************************************************************************
  ****************************************************************************
  **                                                                        **
  **                     class Date declaration                             **
  **                                                                        **
  **                 This class declaration is provided to                  **
  **                 students in COSC 1030 Fall 2024 to use in              **
  **                 part or in total for class projects.                   **
  **                 Students may use this code as their                    **
  **                 own, without any attribution.                          **
  **                                                                        **
  ****************************************************************************
  ****************************************************************************/
 
 class Date
 {
         // can NOT be implemented in-line 
     friend std::istream& operator>>(std::istream&, Date&);
     friend std::ostream& operator<<(std::ostream&, const Date&);
 
 
 private:
 
     int yyyy; 
     int mm;   
     int dd;   
 public:
     // REMEMBER in-line implementation restricted to those methods
         //          that can be written with only one C++ statement
         //          all other methods must be implemented outside of 
         //          the class declaration (inside the Resources.cpp file 
     Date(int=MIN_YYYY, int=MIN_MM, int=MIN_DD); //yyyy, mm, dd
     Date(const Date&);
     void setDate(int, int, int);  //yyyy, mm, dd
     void setDate(const Date&);
     Date& operator=(const Date&);
     int getYear() const;
     int getMonth() const;
     int getDay() const;
     bool operator ==(const Date&) const;
     bool operator !=(const Date&) const;
     bool operator <=(const Date&) const;
     bool operator <(const Date&) const;
     bool operator >=(const Date&) const;
     bool operator >(const Date&) const;
 
 }; //end class Date declaration 
 
 
 
 /****************************************************************************
  ****************************************************************************
  **                                                                        **
  **                 class Time declaration                                 **
  **                                                                        **
  **                 This class declaration is provided to                  **
  **                 students in COSC 1030 Fall 2024 to use in              **
  **                 part or in total for class projects.                   **
  **                 Students may use this code as their                    **
  **                 own, without any attribution.                          **
  **                                                                        **
  ****************************************************************************
  ****************************************************************************/
 
 class Time
 {
         // can NOT be implemented in-line 
     friend std::istream& operator>>(std::istream &in, Time &t);
     friend std::ostream& operator<<(std::ostream &os, const Time &t);
 
 private:
 
     int hh; 
     int mm; 
 public:
     Time(int = DEFAULT_H, int = DEFAULT_M);
 
     void setTime(int, int);
 
     int getHour() const {return hh;}  
     int getMinute() const {return mm;} 
 
 
     Time& operator=(const Time&);
 
     bool operator==( const Time& ) const;
     bool operator!=( const Time& ) const;
     bool operator>=( const Time& ) const;
     bool operator>( const Time& ) const;
     bool operator<=( const Time& ) const;
     bool operator<( const Time& ) const;
 
 }; //END class Time declaration
 
 
 
 
 
 
 
 
 #endif  /*  __COSC1030_FALL2024_P3_RESOURCES_H__  */