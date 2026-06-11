#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a, b, c;
int main() {

    getline( cin,a );
    b = a;
    reverse( a.begin(),a.end() );
    for( int i = 0; i < a.size(); i ++ ) {

           if( a[i] == 'p' ) {
               a[i] = 'q';
           }
           else if( a[i] == 'q' ) {
               a[i] = 'p';
           }
           else if( a[i] == 'b' ) {
               a[i] = 'd';
           }
           else if( a[i] == 'd' ) {
               a[i] = 'b';
           }
    }
    if( a == b ) {
        cout << "Yes" << endl;
        return 0;
    }
    else {
        cout << "No" << endl;
        return 0; 
    }
    return 0;
}