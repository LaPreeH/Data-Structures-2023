#include <iostream>
using namespace std;
#include <limits> // Stricly for numeric limits function
#include <nlist.h>

// This function will take an array of a size defined and filled by the user (in this case) and will perform a sort from 
// smallest to largest integer values. This sort will happen by taking two adjacent values and comparing them. 
// If the first value is larger than the second value, they will be swapped and if the second value is larger, they will stay in their places.
// The comparisons will keep reoccuring until the lists last two values are compared.

void BubbleSort(int arr[], int SIZE){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void PrintArray(int arr[], int SIZE){ // Function to print an array to the terminal in a single line
    for (int i = 0; i < SIZE; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int SIZE; // Initialize a size variable for user input to decide it

    // This while loop below is defined to get user input for the size of the array. 
    // If the user enters anything other than an integer it will clear the error and ask the user for input once again until an integer is returned.
     while (true){
        cout << "Enter a size for the array: ";
        cin >> SIZE;

        if (cin.fail() || SIZE <= 0) {
            // Clear error state if the input fails
            cin.clear();
            // Ignore bad input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR: Must enter a valid positive integer!" << endl;
        } else {
            break; // If a correct input is entered, this loop will be broken out of and the algorithm will continue
        }
    }
    
    int arr[SIZE]; // Define an array of the size that was entered by the user.

    // The following block of code will keep asking the user to input values (integers) to populate the array.
    // This process will keep repeating until the size of the array is filled with an integer value

    for (int i = 0; i < SIZE; i++){
        cout << "Enter a integer for the #" << i + 1 << " element of the array: ";
        cin >> arr[i];
    }

    cout << "The original array: " << endl;
    
    PrintArray(arr, SIZE);
    cout << endl;


    cout << "The sorted array:" << endl;

    BubbleSort(arr, SIZE);
    PrintArray(arr, SIZE);
    cout << endl;

    return 0;
}
