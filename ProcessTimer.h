/*
*  ProcessTimer.h
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


#ifndef __Process_Timer_h_
#define __Process_Timer_h_




#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>


class ProcessTimer
{
    friend std::ostream& operator<<(std::ostream&, const ProcessTimer&);
    
private:
    clock_t timeStart; //start time
    clock_t timeEnd; //end time
    
public:
    ProcessTimer();
    ProcessTimer(clock_t);
    ~ProcessTimer();
    void setTimeStart(clock_t);
    void setTimeEnd(clock_t);
    clock_t getTimeStart();
    clock_t getTimeEnd();
    double getTimeElapsed();
    
}; //end class ProcessTimer
 
 
#endif