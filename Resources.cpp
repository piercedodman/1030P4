/*
 *  Resources.cpp
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



#include "Resources.h"



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                                                                        **
 **                 class Date implementation code                         **
 **                                                                        **
 **                     NOT FOR DISTRIBUTION                               **
 **                                                                        **
 **                                                                        **
 **       Function "banners" are left in to help keep track                **
 **       of code that must be added.                                      **
 **                                                                        **
 **       Some function stubs are given, implementation code for           **
 **       those functions still must be written.                            **
 **                                                                        **
 **       Doxygen comments are also left in for reference.                 **
 **       They may help when you start work on Homework #6.                **
 **                                                                         **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 *                    Date class default constructor                        *
 ****************************************************************************/

/**
 * <P>Constructor with parameters, also default constructor since all
 * parameters have default values in the class declaration.</P>
 * <P>Sets the yyyy, mm, and dd data members to values passed in to the parameters.</P>
 * <P>Shall call the setDate method with integer parameters.
 * The setDate(int,int,int) method is responsible for validation testing,
 * throwing execptions as appropriate, and initializing the yyyy, mm, and dd data members.</P>
 *
 * @param  year an int value in [1492, 2192]
 * @param  month an int value in [1, 12]
 * @param  day an int value in [1-29, 30, 31] depending on the month (ignore leap years)
 * @throws invalid_argument (via setDate(int,int,int)) if any parameter fails validation
 */

Date::Date(int year, int month, int day)
{
    setDate(year, month, day);
}


/****************************************************************************
 *                      Date class copy constructor                         *
 ****************************************************************************/

/**
 * <P>Copy constructor.</P>
 * <P>Sets the yyyy, mm, and dd data members to values of the corresponding
 * data members of the Date object passed in to the parameter.</P>
 * <P>Shall call the setDate method with integer parameters.
 * The setDate(int,int,int) method is responsible for validation testing,
 * throwing execptions as appropriate, and initializing the yyyy, mm, and dd data members.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  otherDate a const reference to another Date object
 * @throws invalid_argument (via setDate(int,int,int)) if any parameter fails validation
 */

// function stub given for the copy constructor
Date::Date(const Date& otherDate)
{
    setDate(otherDate.yyyy, otherDate.mm, otherDate.dd);
} //END Date class copy constructor



/****************************************************************************
 *                   Date class member function setDate                     *
 ****************************************************************************/

/**
 * <P>Member function to set the yyyy, mm, and dd data members to
 * to the values passed in to the three integer parameters.</P>
 * <P>If any values passed to setDate fail validation, then
 * set all data members to the minimum values listed
 * in the project specification.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  year an int value
 * @param  month an int value
 * @param  day an int value
 * @throws invalid_argument if any parameter fails validation
 */

// function stub given for the setDate function 
void Date::setDate(int year, int month, int day)
{
    static const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year < 1492 || year > 2192)
        throw bad_date_component("Invalid year value");
    if (month < 1 || month > 12)
        throw bad_date_component("Invalid month value");

    int maxDays = daysPerMonth[month - 1];

    if (month == 2) {
        // Leap year if divisible by 4 AND (not divisible by 100 OR divisible by 400)
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            maxDays = 29;
        }
    }

    if (day < 1 || day > maxDays)
        throw bad_date_component("Invalid day value");

    yyyy = year;
    mm = month;
    dd = day;
} //END member function setDate



/****************************************************************************
 *              Date class member overloaded function setDate               *
 ****************************************************************************/

/**
 * <P>Overloaded member function.</P>
 * <P>Sets the yyyy, mm, and dd data members to values of the corresponding
 * data members of the Date object passed in as a parameter.</P>
 * <P>Shall call the setDate method with data member values of the object being copied from.
 * The setDate(int,int,int) method is responsible for validation testing,
 * throwing execptions as appropriate, and updating the yyyy, mm, and dd 
 * data members of the object being copied to.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  otherDate a const reference to another Date object
 * @throws invalid_argument (via setDate(int,int,int)) if any parameter fails validation
 */

// function stub given for overloaded setDate function
void Date::setDate(const Date& otherDate)
{
    setDate(otherDate.yyyy, otherDate.mm, otherDate.dd);
} //END overloaded Data class setDate function



/****************************************************************************
 *                   Date class member function getDay                      *
 ****************************************************************************/

/**
 * Returns this Date object's dd data member.
 *
 * @return an int representing the day
 */

// function stub given for the getDay function 
// note that the function stub for a value returning function must have a "dummy"
// return statement as a "place holder" for the real return statement
int Date::getDay() const
{
    return dd;
}



/****************************************************************************
 *                 Date class member function getMonth                      *
 ****************************************************************************/

/**
 * Returns this Date object's mm data member.
 *
 * @return an int representing the month
 */
int Date::getMonth() const
{
    return mm;
}



/****************************************************************************
 *                  Date class member function getYear                      *
 ****************************************************************************/

/**
 * Returns this Date object's yyyy data member.
 *
 * @return an int representing the year
 */
int Date::getYear() const
{
    return yyyy;
}




/****************************************************************************
 *               Date class overloaded assignment operator                  *
 ****************************************************************************/

/**
 * <P>Overloaded assignment operator.</P>
 * <P>Sets the yyyy, mm, and dd data members to values of the corresponding
 * data members of the Date object passed in as a parameter.</P>
 * <P>Shall test for self assignment (not an issue with this class, but
 * good habit nevertheless).</P>
 * <P>Shall call the setDate method with data member values of the object being copied from.
 * The setDate(int,int,int) method is responsible for validation testing,
 * throwing execptions as appropriate, and updating the yyyy, mm, and dd 
 * data members of the object being copied to.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  rhsObj a const reference to another Date object
 * @return a reference to the left hand side operand (the object being copied to)
 * @throws invalid_argument (via setDate(int,int,int)) if any parameter fails validation
 */

// function stub given for the overloaded assignment operator
Date& Date::operator=(const Date& rhsObj)
{
    if (this != &rhsObj)
     {
         setDate(rhsObj.yyyy, rhsObj.mm, rhsObj.dd);
     }
    // Note this is the real return statement for this function
    // We will discuss in class how the statement returns the correct object
    return *this;

} //END overload assignment operator for Date



/****************************************************************************
 *                 Date class stream extraction operator                    *
 ****************************************************************************/

/**
 * <P>friend function, overloaded stream extraction operator</P>
 * <P>Extracts values for a Date object's data members
 * from the input stream.</P>
 * <P>The input format is assumed to yyyy/mm/dd, be aware that
 * the year will always be a 4-digit number, but the month and day
 * values could be either 2-digit or 1-digit numbers.</P>
 * <P>After the values are extracted, the modified input stream is returned.</P>
 * <P>Shall call the setDate method with values extracted from the stream.
 * The setDate(int,int,int) method is responsible for validation testing,
 * throwing execptions as appropriate, and updating the yyyy, mm, and dd 
 * data members.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  is  the input stream for extraction
 * @param  rhsObj  a reference to a Date object to store the extracted information
 * @return  the modified input stream
 * @throws invalid_argument (via setDate method) if any date component fails validation tests
 * @throws invalid_argument if the stream is initially in a failed state
 * @throws runtime_error if the stream fails while while the operator is executing
 */

std::istream& operator>>(std::istream& is, Date& d)
{
    int year, month, day;
    char slash;
    
    if (!is)
        throw std::invalid_argument("Input stream is in a failed state");

    is >> year >> slash >> month >> slash >> day;

    if (!is)
        throw std::runtime_error("Error extracting values from the input stream");

    d.setDate(year, month, day);

    return is;
}



/****************************************************************************
 *                  Date class stream insertion operator                    *
 ****************************************************************************/

/**
 * <P>overloaded stream insertion operator.</P>
 * <P>Inserts a Date object into the output stream
 * and returns the modified output stream.</P>
 * <P>The output format is the same as the input format expected
 * by the overloaded stream extraction operator: yyyy/mm/dd, unlike
 * the stream extraction operator, the stream insertion operator
 * shall always output months and days having 2-digits (use left
 * padding with a 0 for days and months less than 10)</P>
 *
 * @param  os  a reference to the output stream 
 * @param  rhsObj  a const reference to the Date object for output to the stream
 * @return  the modified output stream
 * @throws invalid_argument the stream is initially in a failed state
 *
 */

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    if (!os)
        throw std::invalid_argument("Output stream is in a failed state");

    os << std::setfill('0') << std::setw(4) << d.yyyy << '/'
       << std::setw(2) << d.mm << '/'
       << std::setw(2) << d.dd;

    return os;
}




/****************************************************************************
 *                Date class overloaded equality operator                   *
 ****************************************************************************/

/**
 * <P>overloaded equality operator.</P>
 * <P>Returns true if this Date object is equal to the Date object passed
 * as the parameter; returns false otherwise.</P>
 * <P>Take note that the testing Date objects for equality and inequality is
 * relatively easy.  Some of the other overloaded relational operators
 * will require some additional work.</P>
 * <P>Reminder: Do NOT put abnormal exits in your code.  There should be only 
 * only return.</P>
 *
 * @param rhsObj a const reference to the Date object to be compared (the right hand side object)
 * @return bool indicating if the objects are equal
 */

bool Date::operator==(const Date& rhsObj) const
{
    return (yyyy == rhsObj.yyyy && mm == rhsObj.mm && dd == rhsObj.dd);
}

/****************************************************************************
 *               Date class overloaded inequality operator                  *
 ****************************************************************************/

/**
 * <P>overloaded inequality operator.</P>
 * <P>Returns true if this Date object is NOT equal to the Date object passed
 * in to the parameter; returns false otherwise.</P>
 * <P>Take note that the testing Date objects for equality and inequality is
 * relatively easy.  Some of the other overloaded relational operators
 * will require some additional work.</P>
 * <P>Reminder: Do NOT put abnormal exits in your code.  There should be only 
 * one return.</P>
 *
 * @param rhsObj a const reference to the Date object to be compared (the right hand side object)
 * @return bool indicating if the objects are NOT equal
 */

bool Date::operator!=(const Date& rhsObj) const
{
    return !(*this == rhsObj);
}


/****************************************************************************
 *                   Date class overloaded < operator                       *
 ****************************************************************************/

/**
 * <P>overloaded less than operator.</P>
 * <P>Returns true if this Date object is less than
 * to the Date object passed as the parameter; returns
 * false otherwise.</P>
 * <P>Reminder: Do NOT put abnormal exits in your code  There should be only 
 * one return.</P>
 *
 * @param rhsObj a const reference to the Date object to be compared (the right hand side object)
 * @return bool indicating if the left side object is < the right side object
 */


bool Date::operator<(const Date& rhsObj) const
{
    if (yyyy < rhsObj.yyyy)
        return true;
    else if (yyyy == rhsObj.yyyy && mm < rhsObj.mm)
        return true;
    else if (yyyy == rhsObj.yyyy && mm == rhsObj.mm && dd < rhsObj.dd)
        return true;
    else
        return false;
}


/****************************************************************************
 *                   Date class overloaded <= operator                      *
 ****************************************************************************/

/**
 * <P>overloaded less than or equal to operator.</P>
 * <P>Returns true if this Date object is less than or equal
 * to the Date object passed as the parameter; returns
 * false otherwise.</P>
 * <P>Reminder: Do NOT put abnormal exits in your code  There should be only 
 * one return.</P>
 *
 * @param rhsObj a const referenct to the Date object to be compared (the right hand side object)
 * @return bool indicating if the left side object is <= the right side object
 */

// function stub given for the overloaded greater than or equal to operator
// do NOT put multiple return statements (abnormal exits) in functions like these
// add code that will change the value of the variable answer as appropriate 
// leave return answer; as the last statement in the function
bool Date::operator<=(const Date& rhsObj) const
{
    bool answer = false;

    if (*this == rhsObj || *this < rhsObj)
        answer = true;

    return answer;
} // END overloaded <= operator for Date class



/****************************************************************************
 *                   Date class overloaded > operator                       *
 ****************************************************************************/

/**
 * <P>overloaded greater than operator.</P>
 * <P>Returns true if this Date object is greater than
 * to the Date object passed as the parameter; returns
 * false otherwise.</P>
 * <P>Reminder: Do NOT put abnormal exits in your code  There should be only 
 * one return.</P>
 *
 * @param rhsObj a const reference to the Date object to be compared (the right hand side object)
 * @return bool indicating if the left side object is >= the right side object
 */

bool Date::operator>(const Date& rhsObj) const
{
    return !(*this <= rhsObj);
}



/****************************************************************************
 *                   Date class overloaded >= operator                      *
 ****************************************************************************/

/**
 * <P>overloaded greater than or equal to operator.</P>
 * <P>Returns true if this Date object is greater than or equal
 * to the Date object passed as the parameter; returns
 * false otherwise.</P>
 * <P>Reminder: Do NOT put abnormal exits in your code  There should be only 
 * one return.</P>
 *
 * @param rhsObj a const reference to the Date object to be compared (the right hand side object)
 * @return bool indicating if the left side object is >= the right side object
 */
bool Date::operator>=(const Date& rhsObj) const
{
    return !(*this < rhsObj);
}




/****************************************************************************
 ****************************************************************************
 *****                                                                  *****
 *****               CODE BELOW NOT FOR DISTRIBUTION                    *****
 *****                                                                  *****
 *****    Function "banners" are left in to help keep track             *****
 *****    of code that must be added.                                   *****
 *****                                                                  *****
 *****                                                                  *****
 ****************************************************************************
 ****************************************************************************/


/*#####################################################################################
 ######################################################################################
 ##                                                                                  ##
 ##               function readDoubleQuotedString Implementation Code                ##
 ##                                                                                  ##
 ## Extract a string enclosed within a pair of double quotation marks from a stream. ##
 ##                                                                                  ##
 ######################################################################################
 #####################################################################################*/

/**
 * <P>Stand-alone function readDoubleQuotedString.</P>
 *
 * <P>Returns the text between a pair of double quotes, a double quoted string must be the
 * next contents of the stream object passed into this function.</P>
 *
 * <P>This method expects that the next (NON-blank) character in the stream object will 
 * be a double quotation mark followed by any number of additonal characters.  Another 
 * double quotation mark will indicate the end of the string to return.</P>
 *
 * <P>The method shall return ONLY the characters between the pair of double quotation marks.
 * The beginning and ending double quotation marks are discarded.</P>
 *
 * @param  in a reference to an input stream object
 * @return a string consisting of the text between a pair of double quotes (quotes are not included)
 * @throws invalid_argument if the stream is initially in a failed state
 * @throws runtime_error if the stream fails while the function is executing
 * @throws logic_error if opening double quote was not the first NON-blank character in the stream
 */

std::string readDoubleQuotedString(std::istream& in)
{
    char ch;
    std::string result = "";
    bool inQuotes = false;

    if (!in)
        throw std::invalid_argument("Input stream is in a failed state");

    while (in.get(ch))
    {
        if (ch == '"')
        {
            if (!inQuotes)
                inQuotes = true;
            else
                break;
        }
        else if (inQuotes)
            result += ch;
    }

    if (!inQuotes)
        throw std::logic_error("Opening double quote not found");

    if (!in && !in.eof())
        throw std::runtime_error("Error reading from the input stream");

    return result;
}



/*#####################################################################################
 ######################################################################################
 ##                                                                                  ##
 ##                     function trimSpaces Implementation Code                      ##
 ##                                                                                  ##
 ##                 Remove any extra white space from a string object.               ##
 ##                                                                                  ##
 ######################################################################################
 #####################################################################################*/

/**
 * <P>OPTIONAL: Stand-alone function trimSpaces.</P>
 *
 * <P>Returns a string all extra spaces removed.</P>
 *
 * @param  s the string to be processes, passed by value
 * @return a string containing the exact text as that passed in, but with extra spaces removed
 * @throws out_of_range (via string class) if attempt to access an invalid index of the string
 *
 */

// function stub given for stand-alone function trimSpaces 
string trimSpaces( string s )
{

    //Declare an empty string to be returned.
    //Define a two character window.
    //"Slide" that window over each adjacent pair of
    //characters in the string.  If both characters are blank spaces, then do nothing.
    //If both characters are not blank spaces, then append the first of the two
    //characters to the string being returned.
    //After all adjacent pairs of characters have been tested, the last character in
    //the string must be tested.  If it is a blank space, do nothing, otherwise
    //append it to the string being returned.

    string trimmedString = "";







    return trimmedString;

} //END function trimSpaces()







/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Time implementation code                         **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 1030 Fall 2024 to use in                       **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 *                    Time class default constructor                        *
 ****************************************************************************/

/**
 * <P>Constructor with parameters, also default constructor since all
 * parameters have default values in the class declaration.</P>
 * <P>Sets the hh and mm data members to values passed to parameters.</P>
 * <P>Uses 24-hour format so 24:00 is midnight
 * 12:00 is noon, 13:00 is 1:00 pm, etc.</P>
 * <P>Note that 00:00 is also accepted as midnight but will be converted to 24:00</P>
 * <P>In addition to the range of valid values below, if the hour value is 24, then
 * the minute value must be 00.</P>
 * <P>Shall call the setTime method with integer parameters
 * to perform validation testing and actually initialize hh and mm
 * if all values pass validation.</P>
 *
 * @param  hour an int value in [MIN_HOUR, MAX_HOUR]
 * @param  minute an int value in [MIN_MINUTE, MIN_MINUTE] (must be MIN_MINUTE if hour is MAX_HOUR)
 * @throws invalid_argument if any parameter fails validation
 */

Time::Time(int hour, int minute)
{
    // The DEBUG_TIME identifier is defined using a preprocessor directive in the .h file. 
    // This is a way to easily turn diagnostic output on/off by simply making the 
    // #define DEBUG_TIME a comment in the .h file.  This technique is not required 
    // as part of the project.  However, it can be a very convenient way to 
    // easily start/stop large amounts of diagnostic information from being displayed.
    // Note in the given .h file the define is commented out, so the diagnostic output 
    // will not display.    
    
    #ifdef DEBUG_TIME
    std::cout << "Entered constructor Time::Time(int, int)" << std::endl;
    #endif

    // call method setTime where data validation will be accomplished

    setTime(hour, minute);

    #ifdef DEBUG_TIME
    std::cout << "Exiting constructor Time::Time(int, int)" << std::endl;
    #endif

} //END constructor with parameters for Time class



/****************************************************************************
 *                  Time class member function setTime                      *
 ****************************************************************************/

/**
 * <P>Time class member function to set the hh and mm data members to
 * to the values passed in to the two integer parameters.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  hour an int value
 * @param  minute an int value
 * @throws invalid_argument if any parameter fails validation
 */

void Time::setTime(int hour, int minute)
{
    // The setTime method uses a stringstream to generate an error message 
    // containing heterogeneous data types.
    // This technique is NOT required as part of the project specification, but 
    // it can be a convenient way to create very informative
    // error messages.  Time spent making informative error messages can 
    // make debugging much easier.
    // The starting text of the error message for this method includes the 
    // function name and the values passed into the function.
    std::ostringstream errStrm;
    errStrm << "ERROR: in method Time::setTime( " << hour << ", " << minute << " )\n";

    // Initially set data members to default values.
    // If values passed in to the parameters pass validation, then 
    // the data members will be updated.
    hh = MIN_HOUR;
    mm = MIN_MINUTE;

    bool badArguments = false;

    if ( hour < MIN_HOUR || hour > MAX_HOUR )
    {
        // the hour value passed is not valid
        badArguments = true;
        errStrm << "The hour value argument is not valid.\n";
    }
    else if ( minute < MIN_MINUTE || minute > MAX_MINUTE )
    {
        // the minute value passed is not valid
        badArguments = true;
        errStrm << "The minute value argument is not valid.\n";
    }
    else if ( hour == MAX_HOUR && minute != 0 )
    {
        // if the value passed for hour is 24, then the only valid value for minutes is 0
        badArguments = true;
        errStrm << "The minute value argument must be 0 if the hour value is 24.\n";
    }

    // accept 00:00 as midnight, but silently convert to 24:00
    if ( hour == 0 && minute == 0)
    {
        // NOTE: The minute and hour were both 0, not an error, but 
        //       the hour will be changed to 24 for midnight.

        hour = MAX_HOUR;
    }

    if (badArguments)
    {
        // One or more parameters are not valid, so throw an exception.
        // Note that we do not need a try block to throw the exception.
        // A try block is only necessary if we to handle the exception 
        // (and optionally rethrow) within Time::setTime.

        errStrm << "hour set to MIN_HOUR (" << MIN_HOUR << "), ";
        errStrm << "minute set to MIN_MINUTE (" << MIN_MINUTE << ")\n";
        std::string errMessageText = errStrm.str();

        throw std::invalid_argument(errMessageText);
    }

    // Control will never reach this point of the code unless all 
    // validation checks pass.
    // Both parameters values are valid, so update the object's data members.

    hh = hour;
    mm = minute;

} //END member function Time::setTime



/****************************************************************************
 *                 Time class stream extraction operator                    *
 ****************************************************************************/

/**
 * <P>friend function, overloaded stream extraction operator, Time class</P>
 * <P>Extracts values for a Time object's data members
 * from the input stream.</P>
 * <P>The input format is assumed to hh:mm, be aware that
 * the minute will always be a 2-digit number, right padded with
 * a 0 if necessary, hour values could be either 2-digit or 1-digit numbers.</P>
 * <P>After the values are extracted, the modified input stream is returned.</P>
 * <P>Shall call the setTime(int,int) method passing integer arguments.
 * The setTime(int,int) method is responsible for validation testing,
 * throwing execptions as appropriate, and updating the hh and mm 
 * data members.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  in  the input stream for extraction
 * @param  t  a reference to the Time object for storing the extracted information
 * @return  the modified input stream
 * @throws invalid_argument if the input stream is initially in a failed state
 * @throws invalid_argument (via setTime(int,int)) if any parameter fails validation
 * @throws runtime_error if the input stream fails while the operator is executing
 *
 */

std::istream& operator>>(std::istream &in, Time &t)
{
    // input format is expected to be hh:mm
    // examples:
    // 24:00 for midnight
    // 12:00 for noon
    // 2:45 45 minutes past 2 am
    // 14:45 45 minutes past 2 pm
    // etc.

    char ch;
    int hour = -1;
    int minute = -1;
    std::string errMessage = "";
    bool streamFailed = false;

    // If the input stream is originally in a failed state throw an exception.
    // This is thrown outside of the try block so it will not be
    // handled locally, but will immediately pass control back
    // to the calling function.

    errMessage = "ERROR: in Time class overloaded operator>>\n";
    errMessage += "the input stream is in a failed state, no processing can take place...\n";
    if (!in)
    {
        throw std::invalid_argument(errMessage);
    }

    try
    {
        streamFailed = false;

        in >> hour; //extract the hours and store them in local variable
        if (!in) { streamFailed = true; }

        in >> ch; //extract and discard the dilimiting character
        if (!in) { streamFailed = true; }

        in >> minute; //extract the minutes and store them in local variable
        if (!in) { streamFailed = true; }

        // If stream entered a failed state while extracting values throw an exception.
        // This is thrown inside of the try block so it will be
        // handled locally and then rethrown.

        if(streamFailed)
        {
            errMessage = "WARNING: In Time class overloaded operator>>\n";
            errMessage += "the input stream entered a failed state during processing. ";
            errMessage += "Possible attempt to read past end of file, ";
            errMessage += "time object data members not updated.\n";
            throw std::runtime_error(errMessage);
        }

        t.setTime(hour, minute); // call setTime method where validation will take place
        
    } // END outer try block
    catch (std::invalid_argument &e)
    {
        std::cout << "ERROR: ";
        std::cout << "caught invalid_argument exception in Time class overloaded operator>>\n";
        std::cout << e.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }   
    catch (std::runtime_error &e)
    {
        std::cout << "WARNING: ";
        std::cout << "caught runtime_error exception in Time class overloaded operator>>\n";
        std::cout << e.what() << endl;
        throw;

    }
    catch (std::logic_error &e)
    {
        std::cout << "WARNING: ";
        std::cout << "caught logic_error exception in Time class overloaded operator>>\n";
        std::cout << e.what() << endl;
        throw;

    }
    catch (...)
    {
        std::cout << "ERROR: unknown exception caught in Time class overloaded operator>>\n";
        throw;
    }

    return in;

} //END overloaded stream extraction operator for Time class



/****************************************************************************
 *                 Time class stream insertion operator                     *
 ****************************************************************************/

/**
 * <P>friend function, overloaded stream insertion operator of Time class.</P>
 * <P>Inserts a Time object into the output stream
 * and returns the modified output stream.</P>
 * <P>The output format is the same as the input format expected
 * by the overloaded stream extraction operator: hh:mm, unlike
 * the stream extraction operator, the stream insertion operator
 * shall always output hours and minutes having 2-digits (use left
 * padding with a 0 for hours and minutes less than 10)</P>
 *
 * @param  os  a reference to the output stream
 * @param  t  a const reference to the Time object to be output to the stream
 * @return  the modified output stream
 * @throws invalid_argument if the output stream is initially in a failed state
 */

std::ostream& operator<<(std::ostream &os, const Time &t)
{

    std::string errMessage = "ERROR: in Time class overloaded operator<<\n";
    errMessage += "the output stream is in a failed state, no processing can take place...\n";
    if (!os)
    {
        throw std::invalid_argument(errMessage);
    }

    // if the hour value of minute value is < 10, then pad on the left with a 0 character
    os << std::setfill('0');

    os << std::setw(2) << t.hh;
    os << ":";
    os << std::setw(2) << t.mm;

    // set the fill character back to a blank space to prevent really ugly output of other values
    os << std::setfill(' ');

    return os;

} //END overloaded stream insertion operator for Time class



/****************************************************************************
 *                     Time class assignment operator                       *
 ****************************************************************************/

/**
 * <P>Overloaded assignment operator.</P>
 * <P>Sets the hh amd mm data members to values of the corresponding
 * data members of the Time object passed in as an argument.</P>
 * <P>Should test for self assignment (not an issue with this class, but
 * good habit nevertheless).</P>
 * <P>Should call the setTime method with integer parameters
 * to perform validation testing and actually update hh and mm
 * if all values pass validation.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  rhsObj a const reference to a Time object
 * @throws invalid_argument (via setTime(int,int) method) if any parameter fails validation
 */

Time& Time::operator=(const Time &rhsObj)
{
    // Test for self-assignment.
    // If the address of the left-hand side operand is different from 
    // the address of the right-hand side operand, then the objects 
    // are different and it is NOT self-assignment. 
    // If the addresses are the same, then it is self-assignment (making an 
    // object equal to itself).  This is not considered and error, just skip 
    // everything except the return statement. 
    if (this != &rhsObj)
    {
        // Not a self-assignment so it is OK to proceed.
        // Call the method setTime where validation will be accomplished.

        setTime(rhsObj.hh, rhsObj.mm);
    }

    // Return a reference to the left-hand side operand 
    return *this;

} //END overloaded assignment operator for Time class



/****************************************************************************
 *                 Time class overloaded equality operator                  *
 ****************************************************************************/

/**
 * <P>Overloaded equality operator, Time class.</P>
 * <P>Returns true if the left side Time object is equal to the right side Time object.</P>
 *
 * @param  rhsObj a const reference to a Time object
 * @return true if both objects have the same hour value and minute value, false otherwise
 *
 */

bool Time::operator==( const Time &rhsObj ) const
{
    return ( this->hh == rhsObj.hh && this->mm == rhsObj.mm );

} // END overloaded equality operator for Time class



/****************************************************************************
 *                Time class overloaded inequality operator                 *
 ****************************************************************************/

/**
 * <P>Overloaded inequality operator, Time class.</P>
 * <P>Returns true if the left side Time object is NOT equal to the right side Time object.</P>
 *
 * @param  rhsObj a const reference to a Time object
 * @return true if objects have either different hour value or minute value, false otherwise
 *
 */

bool Time::operator!=( const Time &rhsObj ) const
{
    return !( *this == rhsObj );

} // END overloaded inequality operator for Time class



/****************************************************************************
 *         Time class overloaded greater than or equal to operator          *
 ****************************************************************************/

/**
 * <P>Overloaded greater than or equal to operator, Time class.</P>
 * <P>Returns true if the left side object is greater than or equal to the right side object.</P>
 *
 * @param  rhsObj a const referenct to a Time object
 * @return true if left side object is greater or equal to the right side object, false otherwise
 *
 */

bool Time::operator>=( const Time &rhsObj ) const
{
    bool answer = false;

    if ( *this == rhsObj )
    {
        answer = true;
    }
    else if ( this->hh > rhsObj.hh )
    {
        answer = true;
    }
    else if ( (this->hh == rhsObj.hh) && (this->mm > rhsObj.mm) )
    {
        answer = true;
    }

    return answer;

} // END overloaded greater/equal to operator, Time class



/****************************************************************************
 *               Time class overloaded greater than operator                *
 ****************************************************************************/

/**
 * <P>Overloaded greater than operator, Time class.</P>
 * <P>Returns true if the left side Time object is greater than the right side Time object.</P>
 *
 * @param  rhsObj a const referenct to a Time object
 * @return true if left side object is greater than the right side object, false otherwise
 *
 */

bool Time::operator>( const Time &rhsObj ) const
{
    bool answer = false;

    if ( this->hh > rhsObj.hh )
    {
        answer = true;
    }
    else if ( (this->hh == rhsObj.hh) && (this->mm > rhsObj.mm) )
    {
        answer = true;
    }

    return answer;

} // END overloaded greater than operator, Time class



/****************************************************************************
 *           Time class overloaded less than or equal to operator           *
 ****************************************************************************/

/**
 * <P>Overloaded less than or equal to operator, Time class.</P>
 * <P>Returns true if the left side object is less than or equal to the right side object.</P>
 *
 * @param  rhsObj a const referenct to a Time object
 * @return true if left side object is less or equal to the right side object, false otherwise
 *
 */

bool Time::operator<=( const Time &rhsObj ) const
{
    bool answer = false;

    if ( *this == rhsObj )
    {
        answer = true;
    }
    else if ( this->hh < rhsObj.hh )
    {
        answer = true;
    }
    else if ( (this->hh == rhsObj.hh) && (this->mm < rhsObj.mm) )
    {
        answer = true;
    }

    return answer;

} // END overloaded less than/equal to operator, Time class



/****************************************************************************
 *                 Time class overloaded less than operator                 *
 ****************************************************************************/

/**
 * <P>Overloaded less than operator, Time class.</P>
 * <P>Returns true if the left side Time object is less than the right side Time object.</P>
 *
 * @param  rhsObj a const reference to a Time object
 * @return true if left side object is less than the right side object, false otherwise
 *
 */

bool Time::operator<( const Time &rhsObj ) const
{
    bool answer = false;

    if ( this->hh < rhsObj.hh )
    {
        answer = true;
    }
    else if ( (this->hh == rhsObj.hh) && (this->mm < rhsObj.mm) )
    {
        answer = true;
    }

    return answer;

} // END overloaded greater than operator, Time class








/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **       function parseFullPathAndFileName implementation code            **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 1030 Fall 2024 to use in                       **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 **                                                                        **
 **                                                                        **
 ** I tested this on the class server.  It should work on Windows          **
 ** and Mac as well.  If any issues are found, please let me know.         **
 **                                                                        **
 **                                                                        **
 ** There are probably better ways to accomplish the same thing.           **
 ** Feel free to write your own version if you want to experiment.         **
 **                                                                        **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

void parseFullPathAndFileName( string valueToParse, 
                               string& path, string& fName, string& fNameAndExtension )
{
    string r = "";  // will store the region by the time the function ends 
	string justFileName = "";    // just the input file name without extension 
	string fileNameWithExt = ""; // entire input file name with the extension
    int lastSlash = 0;  // store index of the last back slash or forward slash in the path  
    int i = 0;  // location where file name starts 
    int subStringLength = 0;  // how much of the file name will be used to search for region name
	string startOfFileName = "";  // may be entire file name or just start of the file name 
    int longestRegionName = 0;   // the number of characters in the longest region name 
    string justThePath = "";  // just the path without out file name 
	string s = valueToParse;

    // In Unix and OSX, the last forward slash '/' should indicate the end of the path 
	// and the start of the file name.
	// In Windows, the last back slash '\' should indicate the end of the path 
	// and the start of the file name.
    lastSlash = 0;
    for ( int i=0; i < s.length(); i++ ) { if (s.at(i)=='/' || s.at(i)=='\\') { lastSlash = i; } }
	
	// Loop to extract just the file name from the path and file name string. 
    // If neither a back slash nor forward slash was found, then there must not 
	// be a path stored in the filename string.
	justFileName = ""; // make sure the string begins totally empty 
	i = ( (lastSlash==0) ? lastSlash : lastSlash + 1 );
    while ( i < s.length() && s.at(i)!='.' ) { justFileName += s.at(i++); }
    
	// Loop to extract the file name and extension from the path and file name string.
	fileNameWithExt = ""; // make sure the string begins totally empty 
	i = ( (lastSlash==0) ? lastSlash : lastSlash + 1 );
    while ( i < s.length() ) { fileNameWithExt += s.at(i++); }
	
	// Loop to extract just the path from the path and file name string.
	justThePath = ""; // make sure the string begins totally empty 
	i = 0;
    while ( i < lastSlash ) { justThePath += s.at(i++); }

    path = justThePath;
	fName = justFileName;
	fNameAndExtension = fileNameWithExt;

} // END function getRegionName



