/*
  *  Exceptions.h
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
 
 
 
 
 #ifndef __COSC1030_FALL2024_P3_EXCEPTIONS_H__
 #define __COSC1030_FALL2024_P3_EXCEPTIONS_H__
 
 #include <iostream>
 #include <string>
 #include <sstream>
 #include <exception>
 #include <stdexcept>
 
 using std::string;
 using std::logic_error;
 
 
 
 /****************************************************************************
  ****************************************************************************
  **                                                                        **
  **                    derived exception classes                           **
  **                                                                        **
  **                 This code is provided to students                      **
  **                 in COSC 1030 Fall 2024 to use in                       **
  **                 part or in total for class projects.                   **
  **                 Students may use this code as their                    **
  **                 own, without any attribution.                          **
  **                                                                        **
  ****************************************************************************
  ****************************************************************************/
 
 
 
 class missing_arguments : public logic_error
 {
 public:
     missing_arguments(std::string = "ERROR: missing_arguments");
 
 };  // END exception class missing_arguments
 
 
 
 class file_open_error : public std::invalid_argument
 {
 public:
     file_open_error(std::string = "ERROR: file_open_error");
 
 }; // END file_open_error
 
 
 
 class bad_date_component : public std::invalid_argument
 {
 public:
     bad_date_component(std::string = "ERROR: bad_date_component");
 
 }; // END bad_date_component
 
 
 
 class no_such_object : public std::logic_error
 {
 public:
     no_such_object(std::string = "ERROR: no_such_object");
 
 }; // END no_such_object
 
 
 
 
 
 
 
 
 #endif /*  __COSC1030_FALL2024_P3_EXCEPTIONS_H__  */
 
 
