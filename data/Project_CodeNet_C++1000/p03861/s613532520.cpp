#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a, b, x;
    cin >> a >> b >> x;
    if(a > 0) cout << b/x + 1 - ((a - 1)/x + 1) << endl;
    else cout << b/x + 1 << endl;
}