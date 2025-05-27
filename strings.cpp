#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

int main(){
    // char str[] = {'a', 'b', 'c', 'd', '\n', 'e', 'f', 'g', 'h', '\0'};
    char str[] = "abcd\nefgh";
    cout<<str<<endl;
    cout<< strlen(str) <<endl;
    return 0;
}