#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string s;

int main(){

    cin>>s;
    int len=s.length();
    if(s[0]==s[len-1]){
        if(len&1){//odd number
            printf("Second");
        }
        else {
            printf("First");
        }
    }
    else {
        if(len&1){
            printf("First");
        }
        else {
            printf("Second");
        }
    }
    // getchar();
    // getchar();
    return 0;
}