#include <bits/stdc++.h>
using namespace std;
int main(void){

    string a, b, c;
    cin >> a >> b >> c ;
    
    /*
    if(b - a == c - b){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    */
    
    //cout << a.at(0) - 'a' + 'A' << b.at(0) - 'a' + 'A' << c.at(0) - 'a' + 'A' << endl;
    printf("%c%c%c", a.at(0) - 'a' + 'A' , b.at(0) - 'a' + 'A' , c.at(0) - 'a' + 'A');

    return 0; 
}
