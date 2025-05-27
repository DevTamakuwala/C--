/*
*in this sorting algorithm first we will run a loop for n times and then
*We will compare the adjacent and swap it if required means if we are sorting in the 
*ascendind order then we will check if the first element is greather than the second element or not
*if it is greather then we will swap those two elements and continue checking for till the loops end.

*to optimise this algorithm when the elements are already sorted we can use isSwap variable which will give us the boolean value
*if there has been swapping done.
*and after completing the inner loops each iteration we will check for the isSwap value and if there will not be any swapped
*then we will stop the outter loop and exit the algorithm. by this we can optimise for algorithm for sorted or semi sorted element.


pseudo code:
for i <- 0 to n-1
    isSwap = false
    for j <- 0 to n-i-1
        if arr[j] > arr[j+1]
            swap(arr[j], arr[j+1])
            isSwap = true
    
    if isSwap == false
        return
*/


#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

void bubbleSort(int n, int arr[]){
    
    for(int i = 0; i < n-1; i++){
        bool isSwap = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }

        if(!isSwap){
            return;
        }
    }
}


int main(){
    int arr[] = {1, 10, 2, 20, 40, 50, 5, 55, 60};
    for (int i = 0; i < 9; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubbleSort(9, arr);
    for (int i = 0; i < 9; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}