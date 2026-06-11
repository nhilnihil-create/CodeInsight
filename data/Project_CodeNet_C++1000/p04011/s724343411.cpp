#include <bits/stdc++.h>
using namespace std;
int main(void){

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    //*
    if(a - b >= 0){
        cout << b * c + ( a - b ) * d << endl;
    } else {
        cout << a * c << endl;
    }
    //*/
    
    //cout << b * c + ( a - b ) * d << endl;

    return 0; 
}
