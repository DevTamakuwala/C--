/*
In this is sorting technique we will find the smallest element in the array and 
put it in the starting of the array and again check for the smallest element from 1 to n in the array and again replace it witl 1st
element.

So first we will assume the very first element of the array as the smallest element and then we will compare that element with all the
other elements in the array and we will replace that smallest element wil the first element and then we will move from first element to
the second element and assume the second element as the smallest and then compare other elements with remaining elements and then as
we found the smallest we will replace that smallest element with the second element and keep doing that until the array got sorted.

*/


#include <iostream>
#include <conio.h>
using namespace std;

void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int smallestIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIdx])
            {
                smallestIdx = j;
            }
            
        }
        swap(arr[i], arr[smallestIdx]);
    }
    
}

void display(int arr[]){
    for (int i = 0; i < 9; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1, 10, 2, 20, 40, 50, 5, 55, 60};

    display(arr);
    selectionSort(arr, 9);
    display(arr);
    return 0;
}