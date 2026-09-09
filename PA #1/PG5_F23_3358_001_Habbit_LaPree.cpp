//
// Author /s : LaPree Habbit Jr
//
// Due Date : 10/27/2023
//
// Programming Assignment Number 5
//
// Fall 2023 - CS 3358 - Section 1
//
// Instructor: Husain Gholoom.

// This program will do the following:

// 1. Accepts array size ( n ) from the keyboard. The size must be
//    positive integer that is >= 5
// 2. Use the size from step 1 in order to create an integer array of
//    size n. Populate the created array with random integer values
//    between 100 and 5896 inclusive .
// 3. Display the generated array.
// 4. Write a function that uses recursion in order to display the
//    array in reverse order
// 5. Write a function that uses recursion in order to display squares
//    of integers in ascending order, starting from 1 to n ( array
//    size that was entered from the keyboard ) .
// 6. Write a recursive function that takes the first integer in the
//    reversed array and returns the sum of the digits of that
//    integer.
// 7. Write a function that uses recursion in order to determine
//    whether or not the last number in the reversed array is a
//    prime number . 

#include <iostream>
using namespace std;
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cmath>


// Initializes the size for the array that is given from the keyboard
int getValidSize() {
    cout << "Enter array size. (Must be >= 5) --->  ";
    int n;
    cin >> n;
    cout << endl;

    // Base case
    if (n >= 5) {
        return n;
    }
    else {
        cout << endl;
        cout << "Invalid input. Size must be >= 5" << endl << endl;
        cout << "LaPree Habbit Jr - October 2023" << endl;
    }
}

void populateArray(int arr[], int size) { // Fills the array with random values between 100 and 5896
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (5897 - 100) + 100;
        cout << arr[i] << " ";    
    }
    cout << endl;
}

void reverseArray(int arr[], int size){ // Used to display an array (w/ a defined size) to the screen in reverse ascending order from 1 to n
    if (size < 0){
        return;
    }
    cout << arr[size] << " "; 
    reverseArray(arr, size - 1); //  Recursive call
}

void printNumsAndSquares(int current, int size) {
    if (current > size){  
        return;
    }
    cout << current << "      " << current * current << endl;
    printNumsAndSquares(current + 1, size);
}

int firstReversedIntSum(int num){
        if (num < 10){
             return num; // Base case
        }
        
        return num % 10 + firstReversedIntSum(num / 10); // Recursive call
}

bool isPrime(int num, int divisor = 2){ // Determines if an element of an integer array is prime or not
    // Base case (1)
    if (num <= 1){
        return false;
    }
    // Base case (2)
    if (num == 2){
        return true;
    }
    // Base case (3)
    if (num % divisor == 0){ // Divisible by current divisor
        return false;
    }
    // Base case(4)
    if (divisor > sqrt(num)){
        return true;
    }
    return isPrime(num, divisor + 1); // Recursive call
}


int main(){             
    srand(static_cast<unsigned int>(time(0))); // Seeds the random number generater

    cout << "***  Welcome to my Recursion APP  ***" << endl << endl;

    int size = getValidSize();
    int* arr = new int[size];

    cout << "The Generated Array: ";
    populateArray(arr, size); // Call the function to populate and display the array
    cout << endl;

    cout << "Reversed Array: ";
    reverseArray(arr, size - 1); // Print the populated array to the screen in reverse order
    cout << endl << endl;

    cout << "Table of square values from 1 to " << size << ": " << endl << endl;
    cout << "N" << "      " << "N Squared" << endl;
    printNumsAndSquares(1, size); // Prints numbers in a vertical line from 1 to n (given by the keyboard)
    cout << endl << endl;
    
    int firstInt = arr[size - 1];
                                                    // Finds the single digit sum of the first element in the reversed array
    cout << "sum of " << arr[size - 1] << " digits is: " << firstReversedIntSum(firstInt) << endl << endl;

    cout << "Is " << arr[0] << " a prime number? ";
    
    if (isPrime(arr[0])){ // Implementation to determine if the last element in the reversed array is prime or not
        cout << arr[0] << " is a prime number." << endl << endl;
    }
    else{
        cout << arr[0] << " is not a prime number." << endl << endl;
    }

    cout << "LaPree Habbit Jr - October 2023" << endl;
    delete[] arr;
    return 0;
}
