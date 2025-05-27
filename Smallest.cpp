#include <iostream>
#include <conio.h>
using namespace std;

int main(){

    int arr[] = {5, 15, 1, 5, -15, 24};

    int smallest = arr[0];
    int smallestIndex = 0;
    int largest = arr[0];
    int largestIndex = 0;

    for (int i = 0; i < 6; i++)
    {
        if(arr[i] < smallest){
            smallest = arr[i];
            smallestIndex = i;
        }

        if(arr[i] > smallest){
            largest = arr[i];
            largestIndex = i;
        }
    }

    cout<<"Smallest element is: "<<smallest<<" on "<<smallestIndex<<" position"<<endl;
    cout<<"Largest element is: "<<largest<<" on "<<largestIndex<<" position"<<endl;
    

    return 0;
}