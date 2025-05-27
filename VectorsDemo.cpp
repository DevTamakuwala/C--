#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

int main(){

    vector<int> vec(3, 0);
    vector<int> vec2 = {1, 2, 3, 4};
    vector<int> vec3;

    for(int i : vec){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i : vec2){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"vec3 size: "<<vec3.size()<<endl;
    vec3.push_back(1);
    vec3.push_back(2);
    vec3.push_back(3);
    cout<<"added 1, 2, 3 in vec3: "<<endl;
    for(int i : vec3){
        cout<<i<<" ";
    }
    return 0;
}