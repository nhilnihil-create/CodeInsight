#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll K, T;
    cin >> K >> T;
    vector<ll> a(T);
    ll S = 0,M = -1;
    for(auto &x : a) {
        cin >> x;
        M = max(M,x);
    }
    cout << max(2*M-1-K,0ll) << endl;
}