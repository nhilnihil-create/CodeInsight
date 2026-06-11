#include <bits/stdc++.h>
using namespace std;
int main(void){

    string a, b, c;
    cin >> a >> b >> c;

    /*
    if(a + b == c || a + c == b || b + c == a){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    */
    
    cout << a.at(0) << b.at(0) << c.at(0) << endl;

    return 0; 
}
