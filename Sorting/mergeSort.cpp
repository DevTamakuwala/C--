/*
In merge sort first we will divide all the elements of the array in to two parts until there will be single element in each array.
after that we will merge each individual array in assending or desencing order and we will do this until all the arrays will get merged
in sorted order.

To do this first we will write an logic to divide the array in two parts with the help of mid value
after that we Recursively call the mergeSort function that will perform the division untill there is only one valu left in each array.
Then we will call merge function which will merge the array in sorted order
To merge it in the sorted order the function will first have the temp arrya and 2 indexes of both saperated arrays which will be 
"start" and "mid + 1"
then there will be a while loop which will run until i<=mid or j<=end
In this loop there will be a comparision which will check if the arr[i]<=arr[j]
if arr[i] is greater the it will add it in the temp array and increase the value for i
and if arr[j] is greater the it will add it in the temp array and increase the value for j

after completing this while loop there will be 2 more while loops for remaining values from arr[i] or arr[j] and add those values directly
in the temp array

after this there will be another for loop which will copy the value from temp array to original array
for that the line will be this

arr[i+start] = temp[i]

where i will be index value from loop and start will be the starting value from the mergeSort function.

The time complexity for this will be O(n) only because even in the worst case there will be only n operation for each loop
*/

#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){
    vector<int> temp;
    int i = start;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[i + start] = temp[i];
    }
    
}

void merrgeSort(vector<int> &arr, int start, int end){
    if(start < end){
        int mid = start+(end - start)/2;
        
        merrgeSort(arr, start, mid);
        merrgeSort(arr, mid+1, end);

        merge(arr, start, mid, end);
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
    merrgeSort(arr, 0, arr.size()-1);
    display(arr);
    return 0;
}