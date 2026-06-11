#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(b<c || d<a){
        cout << 0 << endl;
    }
    else if(b>=d && c>=a) cout << d-c << endl;
    else if(d>b && a>c) cout << b-a << endl;
    else if(b-c>=d-a) cout << d-a << endl;
    else if(d-a>b-c) cout << b-c << endl;
}
