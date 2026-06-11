#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, K, T;
    cin >> K >> T;
    vector<ll> a(T);
    vector<ll> cnt(T);
    ll S = 0;
    for(auto &x : a) {
        cin >> x;
    }
    ll M = -1;
    for(ll i = 0; i < T; i++) {
        M = max(M, a[i]);
    }
    if(K-M>=M-1){
        cout << 0 << endl;
    }else{
        cout << M-1-(K-M) << endl;
    }
}