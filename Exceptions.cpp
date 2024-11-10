/*
  *  Exceptions.cpp
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


#include "Exceptions.h"

// Constructor implementation for missing_arguments
missing_arguments::missing_arguments(std::string message) 
    : logic_error(message) {
}

// Constructor implementation for file_open_error
file_open_error::file_open_error(std::string message) 
    : std::invalid_argument(message) {
}

// Constructor implementation for bad_date_component
bad_date_component::bad_date_component(std::string message) 
    : std::invalid_argument(message) {
}

// Constructor implementation for no_such_object
no_such_object::no_such_object(std::string message) 
    : std::logic_error(message) {
}