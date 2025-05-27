#include <iostream>
#include <conio.h>
using namespace std;

void changeA(int &a){
    a=20;
}

int main(){
    int a = 10;
    int arr[]={1,2,3,4,5};
    // *arr = 10;
    for(int i = 0; i<5;i++){
        cout<<arr[i];
    }
    
    return 0;
}