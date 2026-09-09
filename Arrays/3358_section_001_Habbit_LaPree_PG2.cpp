// Author: LaPree Habbit Jr


// Serial Number: 24


// Due Date: 9/18/2023 @ 12:45am
// Programming Assignment Number 2
// Fall 2023 - CS 3358 - Section 001

// Purpose: this is a C++ program that generates an integer random vector array of size N.
// The size of the array is entered from the keyboard and must not exceed 30.
// The program then:
//             A. Generates random numbers between 1 and 5 (inclusive) and stores them
//             in the vector array.

//             B. Display the generated vector array.

//             C. Display a second output in 2 column list. The first column is a list of the
//                distinct array elements in the array; the second column is the count of the
//                number of occurrences of each element in the vector array. The list should
//                be sorted on entries in the first column, largest to smallest.

//             D. Remove the duplicate numbers from the same generated vector array
//                and display the array after all duplicate numbers were removed.

//             E. Sort the vector array that was generated from the previous step in an
//                ascending order from lowest to highest. Display the sorted vector array.

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <limits>
using namespace std;



void randomSeed(){ // Insures that entries are 100% random everytime.
    srand(time(nullptr));
}


int generateRandomNum(){ // Formula for generating a random number.
    return (rand() % 5) + 1;
}


vector<int> getRandomVector(int n){ // Generates the vector using random numbers.
    vector<int> num;
    for (int i = 0; i < n; ++i)
    {
        num.push_back(generateRandomNum());
    }
    return num;
}


void print_vector(vector<int> num){ // Prints the random numbers inside of a vector array.
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
}


void displayOccurrences(const vector<int> vec) { // Displays the distinct numbers of the array and shows the amount of times they showed up in the array.
    vector<int> processed; // Keeps track of numbers that have already been processed.

    for (const int& num : vec) {
        if (find(processed.begin(), processed.end(), num) == processed.end()) {         // Check if this number was already processed
            int n = count(vec.begin(), vec.end(), num);
            cout << num << "       " << n  << endl;
            processed.push_back(num); // Marks the number as processed.
        }
    }
    
}


void removeDuplicatesAndDisplay(vector<int>& num) { // Removes the duplicate elements and displays.
    
    vector<int> uniqueVec; // Create a new vector to store unique values.

    for (const int& num : num) {
        if (find(uniqueVec.begin(), uniqueVec.end(), num) == uniqueVec.end()) {
            uniqueVec.push_back(num);
        }
    }

    
    num = uniqueVec; // Overwrite the original vector with the unique elements ONLY.

    cout << "Array after removing repeated elements: " << endl << endl;

    
    for (const int& num : num) { // Display the vector without duplicates
        cout << num << " ";
    }
    cout << endl << endl;

}

void bubbleSort(vector<int>& num) {
    int n = num.size();
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (num[j] > num[j+1]) {
                // Swap vec[j] and vec[j+1]
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }

}


int main(){
    randomSeed();
    int n;
    int selection;
    
    cout << "Welcome to My Vector APP" << endl << endl;
    cout << "The purpose of this app is to:" << endl;
    cout << "   A. Generate random numbers between 1 and 5 (inclusive) and stores them in the" << endl; 
    cout << "      vector array" << endl;
    cout << "   B. Display the array." << endl;
    cout << "   C. Display an output in a 2 column list. The first column is a list of the" << endl;
    cout << "      distinct array elements; the second column is the count of" << endl;
    cout << "      occurrences of each element. The list should be sorted on entries in the" << endl;
    cout << "      first column, largest to smallest" << endl;
    cout << "   D. Remove repeated numbers from the vector array and display the array." << endl;
    cout << "   E. Sort the vector array in an ascending order from lowest to highest. Display" << endl;
    cout << "      the sorted vector array" << endl << endl;
    

    do
    {
        cout << "Select one of the following: " << endl << endl;
        cout << "1 - Generate The Array" << endl;
        cout << "9 - Exit the app" << endl << endl;
        cout << "Enter your choice: ";

         while (true) { // makes sure that the user cannot enter letters for the selection
        cin >> selection;
        // Check if the input was valid and either 1 or 9
        if (cin.good() && (selection == 1 || selection == 9)) {
            break;
        }
        cin.clear();  // Clear the error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input up to the next newline
        cout << endl;
        cout << "Invalid Selection" << endl << endl;

        cout << "Select one of the following: " << endl << endl;
        cout << "1 - Generate The Array" << endl;
        cout << "9 - Exit the app" << endl << endl;
        cout << "Enter your choice: ";
    }
    if (selection == 1){
            cout << "Enter the size for the array: ";

            while (true) {
            cin >> n;
            cout << endl;
     
        if (cin.good() && (n > 0 || n <= 30)) { // Check if the input was valid and either 1 or 9
            break;
        }
        cin.clear();  // Clear the error input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discards the invalid input up to the next newline
    
        cout << "Invalid. Size must be <= 30" << endl << endl;

        cout << "Select one of the following: " << endl << endl;
        cout << "1 - Generate The Array" << endl;
        cout << "9 - Exit the app" << endl << endl;
        cout << "Enter your choice: ";
            }
        if (n > 0 && n <= 30){
            vector<int> num = getRandomVector(n);
            cout << "The generated array is: " << endl << endl;
            print_vector(num);

            cout << endl << endl;

            cout << "Number" << "  " << "Count" << endl;
            displayOccurrences(num);
            cout << endl << endl;

            removeDuplicatesAndDisplay(num);

            bubbleSort(num);

            cout << "Sorted array: " << endl << endl;
            for (const int& num : num) {
                cout << num << " ";
    }
        cout << endl << endl;
        }
        else{
            do{
            cout << "Invalid. size must be <= 30" << endl;
            cout << "Enter the size for the array: " << endl;
    
            while (true) {
            cin >> n;
            cout << endl;
        
        if (cin.good() && (n > 0 || n <= 30)) { // Check if the input was valid and either 1 or 9
            break;
        }
        cin.clear();  // Clear the error input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discards the invalid input up to the next newline
        
        cout << "Invalid. Size must be <= 30" << endl << endl;

        cout << "Select one of the following: " << endl << endl;
        cout << "1 - Generate The Array" << endl;
        cout << "9 - Exit the app" << endl << endl;
        cout << "Enter your choice: ";
            }
            if (n > 0 && n <= 30){
                vector<int> num = getRandomVector(n);
                cout << "The generated array is: " << endl << endl;
                print_vector(num);

                cout << endl << endl;

                cout << "Number" << "  " << "Count" << endl;
            
                displayOccurrences(num);

                cout << endl << endl;

                removeDuplicatesAndDisplay(num);

                bubbleSort(num);

                cout << "Sorted array: " << endl << endl;
            for (const int& num : num) {
                cout << num << " ";
    }
            cout << endl << endl;
            }
            } while(n < 0 || n > 30);
        }
            do
            {
        cout << "Select one of the following: " << endl << endl;
        cout << "1 - Generate The Array" << endl;
        cout << "9 - Exit the app" << endl << endl;
        cout << "Enter your choice: ";

        while (true) {
        cin >> selection;

        
        if (cin.good() && (selection == 1 || selection == 9)) { // Check if the input was valid and either 1 or 9
            break;
        }

        cin.clear();  // Clear the error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input up to the next newline
        cout << endl;
        cout << "Invalid Selection" << endl << endl;

        cout << "Select one of the following: " << endl << endl;
        cout << "1 - Generate The Array" << endl;
        cout << "9 - Exit the app" << endl << endl;
        cout << "Enter your choice: ";
        }

    if (selection == 1){
            cout << "Enter the size for the array: " << endl;

            while (true) {
            cin >> n;
            
            cout << endl;
       
        if (cin.good() && (n > 0 || n <= 30)) {  // Check if the input was valid and either 1 or 9
            break;
        }
        
        cin.clear();  // Clear the error input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discards the invalid input up to the next newline
        
        cout << "Invalid. Size must be <= 30" << endl << endl;

        cout << "Select one of the following: " << endl << endl;
        cout << "1 - Generate The Array" << endl;
        cout << "9 - Exit the app" << endl << endl;
        cout << "Enter your choice: ";
            }

        if (n > 0 && n <= 30){
            vector<int> num = getRandomVector(n);
            cout << "The generated array is: " << endl << endl;
            print_vector(num);

            cout << endl << endl;

            cout << "Number" << "  " << "Count" << endl;
            displayOccurrences(num);
            cout << endl << endl;

            removeDuplicatesAndDisplay(num);

            bubbleSort(num);

            cout << "Sorted array: " << endl << endl;
            for (const int& num : num) {
                cout << num << " ";
    }
    cout << endl << endl;

        }
        else{
            do{
            cout << "Invalid. size must be <= 30" << endl;
            cout << "Enter the size for the array: " << endl;
    
            

            if (n > 0 && n <= 30){
                vector<int> num = getRandomVector(n);
                cout << "The generated array is: " << endl << endl;
                print_vector(num);

                cout << endl << endl;

                cout << "Number" << "  " << "Count" << endl;
                displayOccurrences(num);
                cout << endl << endl;

                removeDuplicatesAndDisplay(num);

                bubbleSort(num);

                cout << "Sorted array: " << endl << endl;
                for (const int& num : num) {
                cout << num << " ";
                 }
            cout << endl << endl;

            }
            } while(n < 0 || n > 30);
        }
    }
    else if(selection == 9){
            cout << endl;
            cout << "Thank you for using the Vector APP" << endl;
            cout << "LaPree Habbit" << endl;
            cout << "9 - 18 - 2023" << endl;
    }
    else if(selection != 1 || selection != 9){
            cout << endl;
            cout << "***INVALID SELECTION***" << endl << endl;
            }
    } while (selection == 1);
    }
    else if(selection == 9){ // printed when the user would like to exit the program
            cout << endl;
            cout << "Thank you for using the Vector APP" << endl;
            cout << "LaPree Habbit" << endl;
            cout << "9 - 18 - 2023" << endl;
    }
    else if(selection != 1 || selection != 9){ // makes sure only number 1 and 9 can be selected
            cout << endl;
            cout << "Invalid Selection" << endl << endl;
            }
    } while (selection != 1 && selection != 9);

    return 0;
}
