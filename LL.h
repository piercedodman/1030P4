/*
  *  LL.h
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
 
 
 
 
 #ifndef __COSC1030_FALL2024_P4_LL_H__
 #define __COSC1030_FALL2024_P4_LL_H__
 
 
 #include <vector>
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <cstdlib>
 #include <sstream>
 
 #include "Exceptions.h"
 #include "Resources.h"
 
 //#define DEBUG_LL_POP_BACK
 //#define DEBUG_COPY_LIST
 //#define DEBUG_LL_INSERT
 //#define DEBUG_DESTRUCTOR
 //#define DEBUG_I_BUBBLE
 //#define DEBUG_BUBBLE
 //#define DEBUG_SELECTION
 //#define DEBUG_LINEAR

 using std::vector;
 using std::string;
 using std::endl;
 using std::cout;
 
 
 const int LOOP_OUTPUT_FREQUENCY = 5000;   //new for P3 (optional)
 const int SORT_OUTPUT_FREQUENCY = 750;    //new for P3 (optional)
 
 
 /**********************************************************
  *                                                        *
  *                                                        *
  *                  Project #3 classes                    *
  *                                                        *
  *                                                        *
  **********************************************************/
 
 
 
 /****************************************************************************
  *                                                                          *
  *                       class Node declaration                             *
  *                                                                          *
  ****************************************************************************/
 
 
 template <typename T>
 class Node
 {
 public:
     T info;
     Node<T> *next;
     Node<T> *previous;
 
     Node(T = T(), Node<T> *next = NULL, Node<T> *previous = NULL);
 
 }; //END declaration templatized class Node
 
 
 
 /****************************************************************************
  *                                                                          *
  *                   class LL_iterator declaration                          *
  *                                                                          *
  ****************************************************************************/
 
 template <typename T>
 class LL_iterator
 {
 
 private:
     Node<T> *current;
     //pointer to point to the current
     //node in the linked list
 
 public:
 
     LL_iterator();
     //default constructor
     //Postcondition: current = NULL;
 
     LL_iterator(Node<T> *ptr);
     //constructor with parameter
     //Postcondition: current = ptr;
 
     T& operator*();
     //overloaded dereferencing operator
     //Postcondition: Returns a reference to the info contained in the node
 
     LL_iterator<T> operator++();
     //overloaded pre-increment operator
     //Postcondition: The iterator is advanced to the next node in the linked list
 
     LL_iterator<T> operator--();
     //overloaded pre-decrement operator
     //Postcondition: The iterator is moved to the previous node in the linked list
 
     bool operator==(const LL_iterator<T> &rhsObj) const;
     //overloaded equality operator
     //Postcondition: Returns true if this iterator is equal to the
     //               iterator specified on the right hand side
     //               otherwise returns false
 
     bool operator!=(const LL_iterator<T> &rhsObj) const;
     //overloaded equality operator
     //Postcondition: Returns true if this iterator is NOT equal to the
     //               iterator specified on the right hand side
     //               otherwise returns false
 
 
 }; //END class LL_iterator
 
 
 
 /****************************************************************************
  *                                                                          *
  *                        class LL declaration                              *
  *                                                                          *
  ****************************************************************************/
 
 
 template <typename T>
 class LL
 {
     template <typename F>
     friend std::ostream& operator<<(std::ostream& os, const LL<F> &rhsObj);
 
 private:
     unsigned count;   
     Node<T> *header;       
     Node<T> *trailer;      
 public:  // normally these would be private member functions
          // they are made public in this project to facilitate Autograder testing
 
     void copyList(const LL<T>&);
     void initialize();
 
     void remove(unsigned ndx);
 
 public:
     LL();
     LL(const LL<T>&);
     ~LL();
 
     LL<T>& operator=(const LL<T>&);
 
     void insert(unsigned ndx, T);  // optional will not be tested
 
     void push_back(T);
     void pop_back();
     T& back() const;
 
     void push_front(T);
     void pop_front();
     T& front() const;
 
     void clear();
     bool empty() const;
     unsigned size() const {return count;}
 
     T& at(unsigned ndx) const;
     T& operator[](unsigned ndx) const;
 
     void bubbleSortI();    
     void bubbleSort();     
     void selectionSort();  
     void insertionSort();  
     unsigned linearSearch(T lookFor) const;  
     unsigned binarySearch(T lookFor) const;  
     LL_iterator<T> begin();  
     LL_iterator<T> end();    
 }; //END declaration templatized class LL
 
 
 
 
 /****************************************************************************
  ****************************************************************************
  **                                                                        **
  **                      class Node implementation                         **
  **                                                                        **
  ****************************************************************************
  ****************************************************************************/
 
 
 
 /****************************************************************************
  *                         default constructor                              *
  ****************************************************************************/
 
 template <typename T>
 Node<T>::Node(T infoValue, Node<T> *nPtr, Node<T> *pPtr)
 {
    info = infoValue;
    next = nPtr;
    previous = pPtr;
 
 
 } //END Node<T>::Node(T infoValue, Node *nodePtr)
 
 
 /****************************************************************************
  ****************************************************************************
  **                                                                        **
  **                       class LL implementation                          **
  **                                                                        **
  ****************************************************************************
  ****************************************************************************/
 
 
 
 /****************************************************************************
  *                        begin method LL class                             *
  ****************************************************************************/
 
 template <typename T>
 LL_iterator<T> LL<T>::begin()
 {
 if (empty()) {
        throw no_such_object("Cannot get iterator - list is empty");
    }

 return LL_iterator<T>(header->next);
 
         
 } // END implementation code of LL::begin
 
 
 
 /****************************************************************************
  *                          end method LL class                             *
  ****************************************************************************/
 
 template <typename T>
 LL_iterator<T> LL<T>::end()
 {
 
 
 return LL_iterator<T>(trailer);
 
 
 } // END implementation code of LL::end
 
 
 
 /****************************************************************************
  *              non-member function overloaded operator<<                   *
  ****************************************************************************/
 
 template <typename T>
 std::ostream& operator<<(std::ostream& os, const LL<T> &rhsObj)
 {
     if (!os)
         throw invalid_argument("ERROR: in operator<< stream is initially in failed state.");
 
 
 
    try {
        // Output number of items in list
        os << "List contains " << rhsObj.count << " items:" << std::endl;
        
        // If list is not empty, output each item
        if (!rhsObj.empty()) {
            Node<T>* current = rhsObj.header->next;
            unsigned index = 0;
            
            while (current != rhsObj.trailer) {
                os << "Item[" << index << "]: " << current->info << std::endl;
                current = current->next;
                index++;
            }
        }
    }
    catch (...) {
        throw;
    } 
 
 
     return os;
         
 } //END overloaded stream insertion operator for LL<T> class
 
 
 
 /****************************************************************************
  *                  private method copyList of LL class                     *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::copyList(const LL<T> &otherLL)
 {
     //copy constructor
     std::cout << "Inside function copyList() for class LL\n";
 
    try {
        // Clear existing list
        clear();
        
        // Copy nodes from other list
        Node<T>* current = otherLL.header->next;
        while (current != otherLL.trailer) {
            push_back(current->info);
            current = current->next;
        }
    }
    catch (...) {
        clear();
        throw;
    }
 
 
 
     std::cout << "Exiting function copyList() for class LL\n";
 
 } //END function copyList(const LL &otherLL)
 
 
 
 /****************************************************************************
  *                 private method initialize of LL class                    *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::initialize()
 {
     std::cout << "Inside method initialize\n";
 
 
    try {
        // Create sentinel nodes
        header = new Node<T>();
        trailer = new Node<T>();
        
        // Link sentinels together
        header->next = trailer;
        header->previous = nullptr;
        trailer->previous = header;
        trailer->next = nullptr;
        
        // Initialize count
        count = 0;
    }
    catch (std::bad_alloc& e) {
        // Clean up if allocation fails
        delete header;
        delete trailer;
        throw;
    }
 
     std::cout << "Exiting method initialize\n";
 
 } //END private method LL<T>::initialize
 
 
 
 /****************************************************************************
  *                 private method remove of LL class                    *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::remove(unsigned ndx)
 {
 
    if (ndx >= count) {
        throw std::out_of_range("Index out of range in remove()");
    }

    Node<T>* current = header->next;
    for (unsigned i = 0; i < ndx; i++) {
        current = current->next;
    }
    
    current->previous->next = current->next;
    current->next->previous = current->previous;
    delete current;
    count--; 
 
 } // END remove member function of class LL
 
 
 
 /****************************************************************************
  *                         default constructor                              *
  ****************************************************************************/
 
 template <typename T>
 LL<T>::LL()
 {
     //default constructor
 
    initialize();
 
 
 
 } //END default constructor for LL class
 
 
 
 /****************************************************************************
  *                    copy constructor of LL class                          *
  ****************************************************************************/
 
 template <typename T>
 LL<T>::LL(const LL<T> &otherLL)
 {
     //copy constructor
 
 
    initialize();
    copyList(otherLL);
 
 
 } //END LL<T>::LL(const LL<T> &otherLL)
 
 
 
 /****************************************************************************
  *                         destructor of LL class                           *
  ****************************************************************************/
 
 template <typename T>
 LL<T>::~LL()
 {
     //destructor
    #ifdef DEBUG_DESTRUCTOR
     std::cout << "LL<T>::~LL() Entered destructor for class LL<T>\n";
    #endif 
 
 
    clear();
    delete header;
    delete trailer;
 
 
    #ifdef DEBUG_DESTRUCTOR
     std::cout << "LL<T>::~LL() Exiting destructor for class LL<T>\n"
    #endif 
 
 } //END LL<T>::~LL()
 
 
 
 /****************************************************************************
  *                 member function overloaded operator=                     *
  ****************************************************************************/
 
 
 template <typename T>
 LL<T>& LL<T>::operator=(const LL<T> &rhsLL)
 {
     //overloaded assignment operator
 
 
    if (this != &rhsLL) {
        copyList(rhsLL);
    }
 
 
 
     return *this;
 
 } // END LL<T>::operator=(const LL<T> &rhsLL)
 
 
 
 /****************************************************************************
  *                         member function insert                           *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::insert(unsigned ndx, T infoToAdd)
 {
 
 #ifdef DEBUG_LL_INSERT
         cout << "Entered function LL<T>::insert() " << endl;
 #endif
 
 
if (ndx > count) {
        throw std::out_of_range("Index out of range");
    }

    try {
        Node<T>* newNode = new Node<T>(infoToAdd);
        
        // Find the node after which to insert
        Node<T>* current = header;
        for (unsigned i = 0; i < ndx; i++) {
            current = current->next;
        }
        
        // Link the new node
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
        
        count++;
    }
    catch (std::bad_alloc& e) {
        throw;
    } 
 
 
 
 #ifdef DEBUG_LL_INSERT
     cout << "Exiting function LL<T>::insert() " << endl;
 #endif
 
 } //END memmber function insert
 
 
 
 /****************************************************************************
  *                        member function push_back                         *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::push_back(T infoToAdd)
 {
 
 #ifdef DEBUG_LL_PUSH_BACK
     cout << "Entered function LL<T>::push_back() " << endl;
 #endif
 
 
        insert(count, infoToAdd);
                 
                 // REMEMBER you can just call insert and pass infoToAdd along
                 // with the correct index for the insertion point
 
 
 
 #ifdef DEBUG_LL_PUSH_BACK
     cout << "Exiting function LL::push_back() " << endl;
 #endif
 
 } //END LL<T>::push_back(T infoToAdd)
 
 
 
 /****************************************************************************
  *                        member function pop_back                          *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::pop_back()
 {
 
 
        if (empty()){
            throw no_such_object("Cannot pop from empty list");
        }
        remove(count -1);
 
 
 
 } //END LL<T>::pop_back()
 
 
 
 /****************************************************************************
  *                          member function back                            *
  ****************************************************************************/
 
 template <typename T>
 T& LL<T>::back() const
 {
 
        if (empty()) {
            throw no_such_object("List is empty");
        }
        return trailer->previous->info;
 
     //return trailer->info;  // NOTE!! NOT the real return, replace with your return statement
 
 } // END function back, class LL
 
 
 
 /****************************************************************************
  *                       member function push_front                         *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::push_front(T infoToAdd)
 {
 
 
        insert(0, infoToAdd);
                 
                 // REMEMBER you can just call insert and pass infoToAdd along
                 // with the correct index for the insertion point
 
 
 
 } //END LL::push_front(T infoToAdd)
 
 
 
 /****************************************************************************
  *                       member function pop_front                          *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::pop_front()
 {
 
 
        if (empty()){
            throw no_such_object("Cannot pop from empty list");
        }
        remove(0);
 
 
 } //END LL<T>::pop_front()
 
 
 
 /****************************************************************************
  *                          member function front                           *
  ****************************************************************************/
 
 template <typename T>
 T& LL<T>::front() const
 {
 
    if (empty()){
        throw no_such_object("List is empty");
    }
 
    return header->next->info;
 
    // return header->info;  // NOTE!! NOT the real return, replace with your return statement
 
 } // END method front of class LL
 
 
 
 /****************************************************************************
  *                         member function clear                            *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::clear()
 {
     unsigned i = 0;
 
     std::cout << "\tLL<T>::clear() preparing to remove " << count;
     std::cout << " Nodes from the linked list\n";
 
 
 
    Node<T>* current = header->next;
    while (current != trailer) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
        i++;
    }
    
    header->next = trailer;
    trailer->previous = header;
    count = 0; 
 
 
 
     std::cout << "\tLL<T>::clear() removed " << i << " Nodes from the list\n";
     std::cout << "\tLL<T>::clear() new count is: " << count << std::endl;
 
 } //END LL<T>::clear()
 
 
 
 /****************************************************************************
  *                        method empty of LL class                          *
  ****************************************************************************/
 
 template <typename T>
 bool LL<T>::empty() const
 {

    return count == 0;

 } // END LL<T>::empty
 
 
 
 /****************************************************************************
  *                         member function at const                         *
  ****************************************************************************/
 
 template <typename T>
 T& LL<T>::at(unsigned location) const
 {
 
     try
     {
        if (location >= count) {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* current = header->next;
        for (unsigned i = 0; i < location; i++){
            current = current->next;
        }

        return current->info;
 
     }//END try block
 
     catch (std::out_of_range &e)
     {
         throw;
     }
 
 } //END LL::at(int location)
 
 
 
 /****************************************************************************
  *                       overloaded operator[] const                        *
  ****************************************************************************/
 
 template <typename T>
 T& LL<T>::operator[](unsigned ndx) const
 {
     return this->at(ndx);  // Given code, will work if your at method is correctly implemented
 
 } //END overloaded subscript operator
 
 
 
 /****************************************************************************
  *                      member function bubbleSortI                         *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::bubbleSortI()
 {
    #ifdef DEBUG_I_BUBBLE
     cout << "Entered member function bubbleSortI()" << endl;
    #endif
 
    if (count <= 1) return;
    
    unsigned swapCount = 0;
    bool swapped;
    
    do {
        swapped = false;
        for (LL_iterator<T> it = begin(); it != end(); ++it) {
            LL_iterator<T> next = it;
            ++next;
            if (next != end() && *next < *it) {
                // Swap values
                T temp = *it;
                *it = *next;
                *next = temp;
                swapped = true;
                swapCount++;
            }
        }
    } while (swapped);
 
    #ifdef DEBUG_I_BUBBLE
     cout << "Exiting member function bubbleSortI()";
    #endif
     
     cout << "\nResults: swapCount = "
        << swapCount << endl;
 
 } //END member function LL<T>::bubbleSortI()
 
 
 
 /****************************************************************************
  *                       member function bubbleSort                         *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::bubbleSort()
 {
    #ifdef DEBUG_BUBBLE
     cout << "Entered member function bubbleSort()" << endl;
    #endif

    if (count <= 1) return;
    
    unsigned swapCount = 0;
    
    for (unsigned i = 0; i < count - 1; i++) {
        for (unsigned j = 0; j < count - i - 1; j++) {
            if (at(j + 1) < at(j)) {
                // Swap values
                T temp = at(j);
                at(j) = at(j + 1);
                at(j + 1) = temp;
                swapCount++;
            }
        }
    }
     #ifdef DEBUG_BUBBLE    
     cout << "Exiting member function bubbleSort()";
     #endif

     cout << "\nResults: swapCount = " << swapCount << endl;
 
 } //END member function LL<T>::bubbleSort()
 
 
 
 /****************************************************************************
  *                     member function selectionSort                        *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::selectionSort()
 {
    #ifdef DEBUG_SELECTION
    cout << "Entered function selectionSort() " << endl;
    #endif 
 
         if (count <= 1) return;
    
    unsigned swapCount = 0;
    
    for (unsigned i = 0; i < count - 1; i++) {
        unsigned min_idx = i;
        
        for (unsigned j = i + 1; j < count; j++) {
            if (at(j) < at(min_idx)) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            // Swap values
            T temp = at(i);
            at(i) = at(min_idx);
            at(min_idx) = temp;
            swapCount++;
        }
    }
    #ifdef DEBUG_SELECTION
    cout << "Exiting function selectionSort()";
    #endif

    cout << "\nResults: swapCount = " << swapCount << endl;
 
 } // END void LL<T>::selectionSort()
 
 
 
 /****************************************************************************
  *                     member function insertionSort                        *
  ****************************************************************************/
 
 template <typename T>
 void LL<T>::insertionSort()
 {
    #ifdef DEBUG_INSERTION
     cout << "Entered function insertionSort() " << endl;
    #endif

    if (count <= 1) return;
    
    unsigned swapCount = 0;
    
    for (unsigned i = 1; i < count; i++) {
        T key = at(i);
        int j = i - 1;
        
        while (j >= 0 && at(j) > key) {
            at(j + 1) = at(j);
            j--;
            swapCount++;
        }
        at(j + 1) = key;
    }
 
    #ifdef DEBUG_INSERTION
     cout << "Exiting function insertionSort()"; 
    #endif

    cout <<"\nResults: swapCount = "  << swapCount << endl;
 
 } // END void LL<T>::insertionSort()
 
 
 
 /****************************************************************************
  *                      member function linearSearch                        *
  ****************************************************************************/
 
 template <typename T>
 unsigned LL<T>::linearSearch(T lookFor) const
 {
    #ifdef DEBUG_LINEAR
     cout << "Entered function linearSearch(" << lookFor << ")" << endl;
    #endif
 
     // USE THESE VARIABLES OR REPLACE WITH VARIABLES OF YOUR CHOICE
 
     unsigned index = 0;
     bool found = false;
 
 
 
    for (unsigned i = 0; i < count; i++) {
        if (at(i) == lookFor) {
            index = i;
            found = true;
            break;
        }
    }
    
    if (!found) {
        throw no_such_object("Value not found in list");
    }
 
    #ifdef DEBUG_LINEAR
     cout << "Exiting function linearSearch()" << endl;
    #endif

 
     return index;
 
 
 } // END unsigned LL<T>::linearSearch(T lookFor)
 
 
 
 /****************************************************************************
  *                      member function binarySearch                        *
  ****************************************************************************/
 
 template <typename T>
 unsigned LL<T>::binarySearch(T lookFor) const
 {
    #ifdef BINARY_DEBUG
     cout << "Entered function binarySearch(" << lookFor << ")" << endl;
    #endif
 
    if (count == 0) {
        throw no_such_object("List is empty");
    }
  
     bool found = false;
     long  first = 0;
     long  last = count - 1;
     long  middle;
     long position = -1;
 
 
    while (!found && first <= last) {
        middle = first + (last - first)/2;

        if (at(middle) == lookFor) {
            found = true;
            position = middle;
        }
        else if (at(middle) > lookFor) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    
    if (!found) {
        throw no_such_object("Value not found in list");
    }
 
    #ifdef BINARY_DEBUG
    cout << "Exiting function binarySearch()" << endl;
    #endif
    
     return position;
 
 } // END unsigned LL<T>::binarySearch(T lookFor)
 
 
 
 /****************************************************************************
  ****************************************************************************
  **                                                                        **
  **                   class LL_iterator implementation                     **
  **                                                                        **
  ****************************************************************************
  ****************************************************************************/
 
 template <typename T>
 LL_iterator<T>::LL_iterator()
 {
 current = nullptr;
 
 } //END LL_iterator::LL_iterator()
 
 
 
 template <typename T>
 LL_iterator<T>::LL_iterator(Node<T> *ptr)
 {
 current = ptr;
 
 
 } //END LL_iterator::LL_iterator(Node *ptr)
 
 
 
 template <typename T>
 T& LL_iterator<T>::operator*()
 {
    if (current == nullptr || 
        (current->next == nullptr || current->previous == nullptr)) { // Check if sentinel node
        throw no_such_object("Cannot dereference sentinel node or null iterator");
    }
    return current->info;
 
 } //END LL_iterator::operator*()
 
 
 
 template <typename T>
 LL_iterator<T> LL_iterator<T>::operator++()
 {
    if (current->next == nullptr) { // Check if at trailer sentinel
        throw no_such_object("Cannot increment past end of list");
    }
    current = current->next;
    return *this;
 
 } //END LL_iterator::operator++()
 
 
 
 template <typename T>
 LL_iterator<T> LL_iterator<T>::operator--()
 {
 
    if (current->previous == nullptr) { // Check if at header sentinel
        throw no_such_object("Cannot decrement past beginning of list");
    }
    current = current->previous;
    return *this;
 
 } //END LL_iterator::operator++()
 
 
 
 template <typename T>
 bool LL_iterator<T>::operator==(const LL_iterator &rhsObj) const
 {
 
 return current == rhsObj.current;
 
 } //END LL_iterator::operator==()
 
 
 template <typename T>
 bool LL_iterator<T>::operator!=(const LL_iterator &rhsObj) const
 {
 
 
    return !(*this == rhsObj);
 
 } //END LL_iterator::operator!=()
 
 
 
 
 
 
 
 #endif  /*  __COSC1030_FALL2024_P4_LL_H__  */