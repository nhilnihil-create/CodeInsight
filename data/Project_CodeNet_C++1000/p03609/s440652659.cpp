#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    long x,t;
    cin >> x >> t;
    if(x <= t){
        cout << 0 << endl;
    }else{
        cout << x-t << endl;
    }
}

