#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    ll N, T;
    cin >> N >> T;
    vector<int> t(N);
    rep(i,N) cin >> t.at(i);
    sort(t.begin(), t.end());
    ll Tend = 0;
    ll ans = 0;
    rep(i,N) {
        ans += max(0LL, min(T, t.at(i) + T - Tend));
        Tend = t.at(i) + T;
    }
    cout << ans << endl;
}

