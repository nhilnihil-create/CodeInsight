
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
using vl=vector<ll>;
using vb=vector<bool>;
using vs=vector<string>;
using vvl=vector<vl>;
using pll=pair<ll,ll>;
const ll oo =0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define FOR(i,a,b) for(ll i=(a); i<(b); i++)
#define FORD(i,a,b) for(ll i=ll(b)-1;i>=(a);i--)
#define TR(X) ({if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })
int main(){ cin.sync_with_stdio(0);
        ll N; cin >> N;

        vvl adj(N, vl(N));
        FOR(i, 0, N) FOR(j, 0, N) cin >> adj[i][j];

        ll ans = 0;
        FOR(a, 0, N) FOR(b, a+1, N) {
                bool needed = true;
                FOR(c, 0, N) {
                        if (a == c || b == c) continue;

                        if (adj[a][c] + adj[c][b] < adj[a][b]) {
                                cout << -1 << endl;
                                return 0;
                        } else if (adj[a][c] + adj[c][b] == adj[a][b]) {
                                needed = false;
                        }
                }
                if (needed) ans += adj[a][b];
        }
        cout << ans << endl;
} //cin.tie(0) bei schnellem Wechseln
