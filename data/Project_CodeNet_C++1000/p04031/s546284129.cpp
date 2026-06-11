#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
    ll n; cin >> n;
    vector <ll> v(n);
    ll sum = 0;
    rep(i, n) {
        cin >> v.at(i);
        sum += v.at(i);
    }
    ll mean1 = sum/n, mean2 = sum/n+1;
    ll res1 = 0, res2 = 0;
    rep(i, n) {
        res1 += (ll)pow(v.at(i)-mean1, 2);
        res2 += (ll)pow(v.at(i)-mean2, 2);
    }
    cout << min(res1, res2) << endl;
}