#include <iostream>
#include <conio.h>
using namespace std;

int LinearSearch(int arr[], int value){
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[] = {5, 15, 1, 5, -15, 24};

    int value = -15;
    
    int searched = LinearSearch(arr, value);

    if (searched == -1)
    {
        cout<<value<<" Not found";
    } else {
        cout<<value<<" found at "<<searched<<" position";
    }
    

    return 0;
}