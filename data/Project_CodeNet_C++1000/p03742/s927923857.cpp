#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long X, Y;

int main(){
    cin >> X >> Y;
    if( abs(X-Y) <= 1){
        cout << "Brown" << endl;
    }else{
        cout << "Alice" << endl;
    }
}