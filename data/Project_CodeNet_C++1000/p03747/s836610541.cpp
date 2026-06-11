#include <bits/stdc++.h>

using ll = long long;
using namespace std;
constexpr ll inf = 1e15;
constexpr ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, L, T;
    cin>>N>>L>>T;
    vector<pair<ll, bool>> XW(N);
    for (int n = 0; n < N; n++) {
        cin>>XW[n].first;
        int w;
        cin>>w;
        XW[n].second = (w == 1 ? false : true);
    }

    // XW[0]がT秒までに他の蟻とすれ違う回数
    ll count = 0;
    for (int n = 1; n < N; n++) {
        if (XW[n].second == XW[0].second) continue;
        if (XW[n].second == false) {    // XW[0]は反時計回り、XW[n]は時計回り
            ll dst = XW[0].first + L - XW[n].first;
            if (dst / 2 <= T) count -= 1 + (T * 2 - dst) / L;
        } else {    // XW[0]は時計回り、XW[n]は反時計回り
            ll dst = XW[n].first - XW[0].first;
            if (dst / 2 <= T) count += 1 + (T * 2 - dst) / L;
        }
    }
    if (XW[0].second == false) count %= N;
    else count = count - (ll)floor((double)count / N) * N;

    vector<ll> pos(N);
    for (int n = 0; n < N; n++) {
        if (XW[n].second == false) pos[n] = (XW[n].first + T) % L;
        else pos[n] = (L - (T - XW[n].first) % L) % L;
    }
    ll p0 = pos[0];     // count番目のアリはp0にいる

    vector<ll> ans(N);
    sort(begin(pos), end(pos));
    auto it = lower_bound(begin(pos), end(pos), p0);
    if (next(it) != end(pos) && *next(it) == p0 && !XW[0].second) it = next(it);

    ans[count] = p0;
    it++;
    for (int n = count+1; n % N != count; n++) {
        if (it == end(pos)) it = begin(pos);
        ans[n%N] = *it;
        it++;
    }
    for (int a : ans) cout<<a<<endl;

    return 0;
}