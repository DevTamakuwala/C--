#include <iostream>
#include <conio.h>
using namespace std;


int main(){
    int arr[] = {5, 15, 1, 5, -15, 24};
    int start = 0;
    int end = 5;

    
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}