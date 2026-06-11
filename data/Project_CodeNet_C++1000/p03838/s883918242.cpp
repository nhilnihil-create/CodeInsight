#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    int tot=abs(abs(x)-abs(y));
    if ( (long long)x*y<0 ) {
        tot++;        
    } else {
        if ( x*y==0 ) {
            if ( x>y ) tot++;  
        }
        else {
            if ( x>y ) tot+=2;
        }
    }
    cout << tot << '\n';
    return 0;
}