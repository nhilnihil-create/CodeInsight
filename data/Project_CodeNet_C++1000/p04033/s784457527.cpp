#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for(ll i = k; i < (ll)(n); i++)
using ll = long long;

int main(){
    ll a, b;
    cin >> a >> b;
    ll m = -1;
    if (a * b > 0){
        ll thr = min(b, m);
        if ((abs(a - thr) + 1)%2 == 0) cout << "Positive" << endl;
        else if (a >= 1) cout << "Positive" << endl;
        else cout << "Negative" << endl;
    }
    else cout << "Zero" << endl;
    return 0;
}