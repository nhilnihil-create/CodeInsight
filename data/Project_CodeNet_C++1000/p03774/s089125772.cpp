#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const ll INF = 1001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> ab(n);
    vector<P> cd(m);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    rep(i, m) cin >> cd[i].first >> cd[i].second;
    rep(i, n) {
        ll mi = INF;
        ll ans = 0;
        rep(j, m) {
            if(abs(ab[i].first - cd[j].first) + abs(ab[i].second - cd[j].second) < mi) {
                mi = abs(ab[i].first - cd[j].first) + abs(ab[i].second - cd[j].second);
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
