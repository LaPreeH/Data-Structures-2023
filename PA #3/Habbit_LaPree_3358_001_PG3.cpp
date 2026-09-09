// Author : LaPree Habbit
//
// Serial number : 24
//
// Due Date : 9/29/2023
// Programming Assignment Number 3
// Fall 2023 - CS 3358 - Section 1
//
// Instructor: Husain Gholoom.

//Define a class myInt that has as its single attribute an integer
//variable and that contains member functions for determining the
//following information for an object of type myInt:
        //A. Is it multiple of 7 , 11 , or 13.
        //B. Is the sum of its digits odd or even.
        //C. What is the square root value.
        //D.Is it a prime number.
        //E. Is it a perfect number ( The sum of the factors of a perfect

//number is equal to the number itself – for example : 1 + 2 + 4 + 7 + 14 = 28 , so 28 is a perfect number ).
        //Note : Integer must be >= 10

#include <algorithm>
#include <iostream>
#include <cctype>
using namespace std;

class myInt {
private:
    int value;

    bool isMultipleOf(int num) const {  // Returns a true or false statement due to a number being a multiple of 7, 11, or 13
        return value % num == 0;
    }

    bool isPrime(int num) const { // Determines if a number is prime
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }

public:
    void setValue(int v){
        value = v;
    }
    
    bool isMultipleOf7or11or13() const { // Determines if the number entered is a multiple of 7, 11, or 13
        return isMultipleOf(7) || isMultipleOf(11) || isMultipleOf(13);
    }

    bool isSumOfDigitsEven() const { // Determines if the sum of the digits are evem or not
        int sum = 0;
        int tempValue = value;
        while (tempValue > 0) {
            sum += tempValue % 10;
            tempValue /= 10;
        }
        return sum % 2 == 0;
    }

    double squareRoot() const { // Takes the square root of a number
        int i = 1;
        while (i * i <= value) {
            i++;
        }
        return i - 1;
    }

    bool isPrimeNumber() const { // returns the prime number if true
        return isPrime(value);
    }

    bool isPerfectNumber() const { // Determines if a number is a perfect number
        int sum = 0;
        for (int i = 1; i <= value / 2; i++) {
            if (value % i == 0) {
                sum += i;
            }
        }
        return sum == value;
    }
};

int main() {
    myInt num;

    cout << "Welcome to my Integer Manipulation Program" << endl << endl;

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        int inputValue;
        
        
        while (true) {
        cout << "Enter an integer: ";
        cin >> inputValue;

        if (cin.fail()) { // If the input operation failed
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
            cout << "Error *** – Integer must be >= 100" << endl;
        } 
        else if(inputValue < 100){
            cout << "Error *** Integer must be >= 100" << endl;
        }
        else {
            break; // Exit the loop if the input was valid
        }

        cout << endl;
    }

        num.setValue(inputValue);

        cout << endl << endl;
        
        cout << "A. " << inputValue << " " << (num.isMultipleOf7or11or13() ? "is" : "is not") << " a multiple of 7, 11, or 13" << endl;
        cout << "B. The sum of the digits is " << (num.isSumOfDigitsEven() ? "even" : "odd") << endl;
        cout << "C. SQRT of " << inputValue << " is " << num.squareRoot() << endl;
        cout << "D. " << inputValue << " " << (num.isPrimeNumber() ? "is" : "is not") << " a prime number" << endl;
        cout << "E. " << inputValue << " " <<(num.isPerfectNumber() ? "is" : "is not") << " a perfect number" << endl;

        cout << "Would you like to re-run the program again?" << endl;
        cout << "Enter  Y  or  N ---->   ";

        while (true) {  // Infinite loop to keep asking until valid input
        cin >> choice;

        // Check if the input is a single character and a letter
        if (cin.get() == '\n' && isalpha(choice)) {
            break;  // Exit the loop if the input is a letter
        }

        // Clear any errors and ignore remaining characters in the buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Error *** Invalid choice - Must enter y | Y or n | N" << endl;
    }

        cout << endl << endl;
    }


    cout << "This program is implemented by LaPree Habbit Jr" << endl;
    cout << "September - 2023" << endl;

    return 0;
}
