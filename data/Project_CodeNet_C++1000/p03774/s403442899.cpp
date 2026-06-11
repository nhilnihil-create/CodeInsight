#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll> > s(N);
    vector<pair<ll, ll> > c(M);
    for(ll i = 0; i < N; i++) {
        cin >> s.at(i).first >> s.at(i).second;
    }

    for(ll i = 0; i < M; i++) {
        cin >> c.at(i).first >> c.at(i).second;
    }

    for(ll i = 0; i < N; i++) {
        ll ans = 0;
        ll d = 1e10;
        for(ll j = 0; j < M; j++) {
            if(abs(s.at(i).first - c.at(j).first) + abs(s.at(i).second - c.at(j).second) < d) {
                d = abs(s.at(i).first - c.at(j).first) + abs(s.at(i).second - c.at(j).second);
                ans = j;
            }
        }
        cout << ans + 1 << endl;
    }

    return 0;
}