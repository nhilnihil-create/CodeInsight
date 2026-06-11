#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
int C[3];
int main(){
    cin >> C[0] >> C[1] >> C[2];
    sort(C,C+3);
    if(C[0]==5){
        if(C[1]==5){
            if(C[2]==7){
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}