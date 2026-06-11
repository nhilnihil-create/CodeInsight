#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    string A;
    cin >>s;

    size_t size = s.length();
    A=s[0];

    for(int i=1;i<size;++i){
        if(i%2==0) A=A+s[i];
    }
    cout <<A<<endl;
    return 0;
}