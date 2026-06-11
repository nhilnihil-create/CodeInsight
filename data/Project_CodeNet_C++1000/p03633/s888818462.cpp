#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    ll t = v[0];
    for (int i = 1; i < SZ(v); i++) t = lcm(t, v[i]);
    cout << t << "\n";
}