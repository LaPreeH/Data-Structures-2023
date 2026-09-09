#include <iostream>
using namespace std;

void selectionSort(int a[], int length)
{
    for (int i = 0; i < (length - 1); i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < length; j++)
        {
            if (a[j] < a[min_pos])
            {
                min_pos = j;
            }
        }
        if (min_pos != i){
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }
}

int main(){
    int a[] = {6,5,3,2,1,4};
    int length = 6;

    selectionSort(a, length);

    for (int i = 0; i < length; i++){ // Prints the sorted array to the screen
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}
