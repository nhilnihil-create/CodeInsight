#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string s;
    cin >> s;

    for(char c = 'a'; c <= 'z'; c++){
        if(s.find(c)  == string::npos){
            printf("%c\n", c);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}