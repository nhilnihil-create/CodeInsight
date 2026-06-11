#include <bits/stdc++.h>
using namespace std;
int main(void){

    int a, b, c;
    cin >> a >> b >> c ;
    
    //*
    if( b >= c ){
        cout << "delicious" << endl;
    } else if ( b < c && c <= a + b){
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
    //*/
    
    //cout << a.at(0) - 'a' + 'A' << b.at(0) - 'a' + 'A' << c.at(0) - 'a' + 'A' << endl;

    return 0; 
}
