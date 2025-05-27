/*
In quick sort algorithm first we will decide the pivot index and after that we will Recursively call the quick sort algorithm on left side
and right side.
While finding the pivot index we will first have to choose the pivot and then we will compare all the values with that pivot
value and all the values greather then pivot value will bo on the right side and lesser values will be on the left side.
and the pivot value will be in the middle and at it's actual sorted position.

To find pivot index first we have to determine a pivot value for that here we are considering it as the last value of the array
and we have to declare one vavriable called index which we make space for the elements to be swapped.

after the we will be running a loop from start to end/end-1
In this loop we will check if arr[j] <= pivot means the value is less then or equal to the pivot value or not
if the value is lesser then we will increase the idx value by 1 and replace the arr[idx] with arr[j]
After completing this loop we will again increase the value of index by one and then
swap the arr[end] with arr[idx]
By doing this the pivot value will be on it's actual position in the sorted array. and we will return that index.

after getting the pivot index we will split the array in two parts and call the quickSort function again for
start to pivot - 1 and
pivot + 1 to end
WE WILL DO THIS ONLY WHEN START < END


by doing this our array will be sorted using quick sort.


The time complexity of this in worst case will be O(n^2)
and in average case it will be O(n Log n)

Que :- When there will be worst case complexity in quick sort ? 
Ans :- We will be having worst case complexity at that time when we have pivot as either smallest element or largest element of the array.
*/
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

int position(vector<int> &arr, int start, int end){
    int idx = start-1;
    int pivot = arr[end];
    
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSort(vector<int> &arr, int start, int end){
    if(start < end){
        int pivot = position(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

void display(vector<int> arr){
    for (int i = 0; i < 9; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1, 10, 2, 20, 40, 50, 5, 5, 60};
    display(arr);
    quickSort(arr, 0, arr.size()-1);
    display(arr);
    return 0;
}