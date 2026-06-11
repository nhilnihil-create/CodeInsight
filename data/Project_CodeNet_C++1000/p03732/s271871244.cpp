#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N, WM; cin >> N >> WM;
    map<ll, ll> DP; // key: weight, value: value :-)

    pair<ll, ll> *D = new pair<ll,ll>[N];
    rep(i,N) {
        ll w, v; cin >> w >> v;
        D[i].first  = w;
        D[i].second = v;
    }

    DP[0] = 0;
    for (int i = 0; i < N; i++) {
        for (auto j = DP.rbegin(); j != DP.rend(); j++) {
            ll w = D[i].first + j->first;
            ll v = D[i].second + j->second;
            if (w <= WM) {
                DP[w] = max(DP[w], v);
            }
        }
    }
    ll ma = 0;
    for (auto j = DP.begin(); j != DP.end(); j++) {
        ma = max(ma, j->second);
    }
    cout << ma << endl;
}
