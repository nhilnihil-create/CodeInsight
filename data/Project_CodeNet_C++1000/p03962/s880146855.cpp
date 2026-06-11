#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
    vector <ll> v(3);
    rep(i, 3) cin >> v.at(i);
    sort(v.begin(), v.end());
    ll res = 1;
    rep(i, 2) {
        if (v.at(i) != v.at(i+1)) res++;
    }
    cout << res << endl;
}