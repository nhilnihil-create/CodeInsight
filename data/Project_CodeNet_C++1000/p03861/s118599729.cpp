#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a,b,x;
    cin >> a >> b >> x;

    if(a%x==0 || b%x==0){
        cout << (b-a)/x+1 << endl;
        return 0;
    }

    if(a/x==b/x){
        cout << 0 << endl;
        return 0;
    }

    a = a/x+1;
    b = b/x;
    cout << b-a+1 << endl;

    return 0;
}