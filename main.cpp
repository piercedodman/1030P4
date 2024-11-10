/*
*  main.cpp
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


#include "main.h"
 // Program name + input file

int main(int argc, char* argv[]) {
    try {
        // Check for minimum command line arguments
        if (argc < MIN_CMD_LINE_ARGS) {
            throw missing_arguments("Insufficient command line arguments. Usage: " + 
            string(argv[0]) + " <input_file>");
        }

        // Open input file - use command line argument
        ifstream inFile(argv[1]);
        if (!inFile) {
            throw file_open_error("Failed to open input file: " + string(argv[1]));
        }

        string line;
        int totalDates = 0;
        while(getline(inFile, line)) {
            if(!line.empty()) totalDates++;
        }
        cout << "Dates Read: " << totalDates << endl;

        inFile.clear();
        inFile.seekg(0,ios::beg);

        LL<Date> dateList;
        Date tempDate;
        int count = 0;
        
            cout << "\n----------------------------------------";
            cout << "\nRunning tests for size: " << totalDates;
            cout << "\n----------------------------------------" << endl;
        
        while(count < totalDates && (inFile >> tempDate)) {
            dateList.push_back(tempDate);
            count++;
        }

        if (count == 0) {
            throw runtime_error("No dates were read from the input file");
        }

            // Store original list for resetting between sorts
            LL<Date> originalList = dateList;

            // Test bubbleSortI
            ProcessTimer bubbleITimer;
            cout << "\nBubble Sort (Iterator Version)";
            cout << "\n------------------------------\n";
            bubbleITimer.setTimeStart(clock());
            dateList.bubbleSortI();
            bubbleITimer.setTimeEnd(clock());
            cout << "\nBubbleSortI Time: " << fixed << setprecision(6)
            << bubbleITimer.getTimeElapsed() << " seconds\n";
            
            // Reset list
            dateList = originalList;

            // Test bubbleSort
            ProcessTimer bubbleTimer;
            cout << "\nBubble Sort";
            cout << "\n-----------\n";
            bubbleTimer.setTimeStart(clock());
            dateList.bubbleSort();
            bubbleTimer.setTimeEnd(clock());
            cout << "\nBubbleSort Time: " << fixed << setprecision(6)
            << bubbleTimer.getTimeElapsed() << " seconds\n";
            
            dateList = originalList;

            // Test selectionSort
            ProcessTimer selectionTimer;
            cout << "\nSelection Sort";
            cout << "\n--------------\n";
            selectionTimer.setTimeStart(clock());
            dateList.selectionSort();
            selectionTimer.setTimeEnd(clock());
            cout << "\nSelectionSort Time: " << fixed << setprecision(6)
            << selectionTimer.getTimeElapsed() << " seconds\n";
            
            dateList = originalList;

            // Test insertionSort
            ProcessTimer insertionTimer;
            cout << "\nInsertion Sort";
            cout << "\n--------------\n";
            insertionTimer.setTimeStart(clock());
            dateList.insertionSort();
            insertionTimer.setTimeEnd(clock());
            cout << "\nInsertionSort Time: " << fixed << setprecision(6) <<
             insertionTimer.getTimeElapsed() << " seconds\n";

            // Search tests (on sorted list)
            if (!dateList.empty()) {
                Date searchTarget = dateList.at(dateList.size() / 2);  // Middle element

            ProcessTimer linearTimer;
            cout << "\nLinear Search";
            cout << "\n-------------";
            cout << "\nSearching for: " << searchTarget << "\n";
            linearTimer.setTimeStart(clock());
            try {
                unsigned pos = dateList.linearSearch(searchTarget);
                cout << "\nFound at position: " << pos << endl;
            }
            catch (const no_such_object& e) {
                cout << "\nSearch failed: " << e.what() << endl;
            }
            linearTimer.setTimeEnd(clock());
            cout << "\nTime: " << fixed << setprecision(6)
            << linearTimer.getTimeElapsed() << " seconds\n";

            ProcessTimer binaryTimer;
            cout << "\nBinary Search";
            cout << "\n-------------";
            cout << "\nSearching for: " << searchTarget << "\n";
            binaryTimer.setTimeStart(clock());
            try {
                unsigned pos = dateList.binarySearch(searchTarget);
                cout << "\nFound at position: " << pos << endl;
            }
            catch (const no_such_object& e) {
                cout << "\nSearch failed: " << e.what() << endl;
            }
            binaryTimer.setTimeEnd(clock());
            cout << "\nTime: " << fixed << setprecision(6)
            << binaryTimer.getTimeElapsed() << " seconds\n\n";
            }


        inFile.close();
    }
    catch (const missing_arguments& e) {
        cerr << e.what() << endl;
        // return 1;
    }
    catch (const file_open_error& e) {
        cerr << e.what() << endl;
        // return 1;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        // return 1;
    }

    return 0;
}