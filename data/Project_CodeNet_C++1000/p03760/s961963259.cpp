#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
# define INT_MAX implementation-defined
using namespace std;
int main(){
    string s, t; cin >> s >> t;
    int a = s.size();
    int b = t.size();
    if(a<b){
        for(int i=0; i<a; i++){
            cout << s.at(i) << t.at(i);
        }
        cout << t.substr(a, b-a+1) << endl;
        return 0;
    }
    else if(b<a){
        for(int i=0; i<b; i++){
            cout << s.at(i) << t.at(i);
        }
        cout << s.substr(b, a-b+1) << endl;
        return 0;
    }
    else{
        for(int i=0; i<b; i++){
            cout << s.at(i) << t.at(i);
        }
        cout << endl;
        return 0;
    }
}