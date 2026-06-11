#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll N, M; cin >> N >> M;
    vvll v(N, vll(N, inf));
    vvll next(N, vll(N));
    rep(i, N) rep(j, N) next[i][j] = j;
    rep(i, M) {
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        v[a][b] = c;
        v[b][a] = c;
    }

    for (ll k = 0; k < N; k++)
        for (ll i = 0; i < N; i++)
            for (ll j = 0; j < N; j++)
                if (v[i][k] + v[k][j] < v[i][j]) {
                    v[i][j] = v[i][k] + v[k][j];
                    next[i][j] = next[i][k];
                }

    set<pair<ll, ll>> st;
    for (ll start = 0; start < N; start++)
        for (ll goal = start + 1; goal < N; goal++) {
            //cout << "start: " << start << ", goal: " << goal << endl;
            for (ll cur = start; cur != goal; cur = next[cur][goal]) {
                //cout << cur << " => " << next[cur][goal] << endl;
                st.insert({min(cur, next[cur][goal]), max(cur, next[cur][goal])});
            }
            //cout << endl;
        }
                

    cout << M - st.size() << endl;
    return 0;
}