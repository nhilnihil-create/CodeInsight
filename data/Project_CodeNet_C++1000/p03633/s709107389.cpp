#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

ll lcm(ll x, ll y){
    return x / gcd(x, y) * y;
}

int main(){
    int n;
    cin >> n;
    vector<ll> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    ll res = t[0];
    for (int i = 0; i < n - 1; ++i) {
        res = lcm(res, t[i+1]);
    }
    cout << res << endl;
}