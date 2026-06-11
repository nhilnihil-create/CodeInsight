#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll x,y;
    cin >> x >> y;
    if(x*y>0){
        if(y>=x) cout << y-x << endl;
        else cout << x-y+2 << endl;
    }
    else if(x*y==0){
        if(y<0 || x>0) cout << abs(x+y)+1 << endl;
        else cout << abs(x+y) << endl;
    }
    else{
        x = abs(x),y=abs(y);
        if(y>=x) cout << y-x+1 << endl;
        else cout << x-y+1 << endl;
    }

    return 0;
}