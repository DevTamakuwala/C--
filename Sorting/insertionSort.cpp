/*
In this first element will be assumed as a sorted element and then remaining elements get chekced and compared for the smaller
element as the smalles element found in the list that element will be replaced by it's previous value and again check with the previous
value of it and if it is still smaller then it will again be replaced and this happnes until there is no element before that element or
that element is bigger then the previous element.

We will take two pointers one is previous and another is current, current will be equal to ith element and previous will equal it i - 1th
element and until previous >= 0 or arr[previous]>current the value of previous is getting changed and after the loop current value will be
assigned on the previous index.
*/



#include <iostream>
#include <conio.h>
using namespace std;

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int prev = i-1;
        while (prev >= 0 && arr[prev]>current)
        {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = current;
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
    insertionSort(arr, 9);
    display(arr);
    return 0;
}