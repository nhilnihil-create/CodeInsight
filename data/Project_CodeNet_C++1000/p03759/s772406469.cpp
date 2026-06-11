#include <iostream>
using namespace std ;
int main (){

int x, s, a ;
cin >> x>>s >> a ;
if ( s-x == a-s ){
    cout << "YES";
}
else {
    cout << "NO";
}
return 0;
}