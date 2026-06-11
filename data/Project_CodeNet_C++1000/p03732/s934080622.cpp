#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    const int N = 4;
    int n, w;
    cin >> n >> w;
    vector<vector<int>> vv(N,vector<int>());
    ll w1,v1;
    cin >> w1 >> v1;
    vv[0].push_back(v1);
    REP(i,n-1) {
        ll w, v;
        cin >> w >> v;
        vv[w-w1].push_back(v);
    }
    REP(i,N) sort(RALL(vv[i]));
    vector<vector<int>> vsum(N,vector<int>{0});
    REP(i,N) REP(j,vv[i].size()) {
        vsum[i].push_back(vsum[i][j] + vv[i][j]);
    }
    int ans = 0;

    for (ll i = 0; i < vsum[0].size(); i++) {
        ll wi = w1 * i;
        if (wi > w) break;

        for (ll j = 0; j < vsum[1].size(); j++) {
            ll wj = wi + (w1+1) * j;
            if (wj > w) break;

            for(ll k = 0; k < vsum[2].size(); k++) {
                ll wk = wj + (w1+2) * k;
                if (wk > w) break;

                for(ll l = 0; l < vsum[3].size(); l++) {
                    ll wl = wk + (w1+3) * l;
                    if (wl > w) break;
                    ans = max(ans,vsum[0][i]+vsum[1][j]+vsum[2][k]+vsum[3][l]);
                    // cerr << i << j << k << l << " " << ans << endl;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}