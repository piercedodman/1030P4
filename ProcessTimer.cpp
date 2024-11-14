/*
 *  ProcessTimer.cpp
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


#include "ProcessTimer.h"





/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **              class ProcessTimer implementation code                    **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 1030 Fall 2024 to use in                       **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/**
 * Default constructor
 * Sets the start time to zero
 * Sets the end time to zero
 *
 */
 
ProcessTimer::ProcessTimer()
{

    timeStart = 0;

    timeEnd = 0;

} // END default constructor for class ProcessTimer



/**
 * Constructor with parameters
 * Sets the start time to the value passed
 * Sets the end time to zero
 *
 * @param  tmSt a clock_t
 *
 */
 
ProcessTimer::ProcessTimer(clock_t tmSt)
{

    timeStart = tmSt;

    timeEnd = 0;

} // END constructor with parameters for class ProcessTimer



/**
 *
 * Destructor
 *
 */
 
ProcessTimer::~ProcessTimer()
{
    //std::cout << "Inside destructor for ProcessTimer object" << std::endl;

} // END destructor for class ProcessTimer



/**
 * Overloaded stream insertion operator
 * Outputs report including start, stop, and elapsed time
 *
 * @param  os a reference to an ostream object
 * @param  tmStmp a constant reference to a ProcessTimer object
 *
 */
 
std::ostream& operator<<(std::ostream &os, const ProcessTimer &tmStmp)
{

    std::cout << "Start time:\t" << tmStmp.timeStart << "\n";

    std::cout << "End time:\t" << tmStmp.timeEnd << "\n";

    std::cout << "Elapsed time:\t";

    std::cout << (tmStmp.timeEnd - static_cast<double>(tmStmp.timeStart))/CLOCKS_PER_SEC;

    std::cout << "\n";

    std::cout << std::endl;

    return os;

} // END overloaded stream insertion operator for class ProcessTimer



/**
 * Sets the start time to the value passed
 *
 * @param  tmStart a clock_t
 *
 */
 
void ProcessTimer::setTimeStart(clock_t tmStart)
{

    timeStart = tmStart;

} // END setTimeStart method of ProcessTimer class



/**
 * Sets the end time to the value passed
 *
 * @param  tmEnd a clock_t
 *
 */
 
void ProcessTimer::setTimeEnd(clock_t tmEnd)
{

    timeEnd = tmEnd;

} // END setTimeEnd method of ProcessTimer class



clock_t ProcessTimer::getTimeStart()
{

    return timeStart;

} // END getTimeStart method of ProcessTimer class



clock_t ProcessTimer::getTimeEnd()
{

    return timeEnd;

} // END getTimeEnd method of ProcessTimer class



double ProcessTimer::getTimeElapsed()
{

    return static_cast<double>( (timeEnd - static_cast<double>(timeStart))/CLOCKS_PER_SEC );

} // END getTimeElapsed method of ProcessTimer class



