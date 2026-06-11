#include <bits/stdc++.h>
using namespace std;
int main(void){

    int a, b, c31 = 0, c30 = 0, c28 = 0;
    cin >> a >> b ;
    
    if(a == 2){
        c28++;
    } else if(a == 4 || a == 6 || a == 9 || a == 11){
        c30++;
    } else {
        c31++;
    }
    
    if(b == 2){
        c28++;
    } else if(b == 4 || b == 6 || b == 9 || b == 11){
        c30++;
    } else {
        c31++;
    }
    
    //*
    if(2 == c28 || 2 == c30 || c31 == 2 ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    //*/
    
    //cout << a.at(0) - 'a' + 'A' << b.at(0) - 'a' + 'A' << c.at(0) - 'a' + 'A' << endl;

    return 0; 
}
