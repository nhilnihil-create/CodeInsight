#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll N;
    cin >> N;
    vector<vector<pll>> G(N);
    REP(i,0,N-1) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }
    ll Q, K;
    cin >> Q >> K;
    --K;
    vec X(Q), Y(Q);
    REP(i,0,Q) {
        cin >> X[i] >> Y[i];
        --X[i]; --Y[i];
    }

    queue<ll> R;
    vec D(N, INF);
    R.push(K);
    D[K] = 0;
    while(!R.empty()) {
        ll v = R.front(); R.pop();
        FORR(ne,G[v]) {
            ll nv = ne.first, d = ne.second;
            if(D[nv] > D[v] + d) {
                D[nv] = MIN(D[nv],D[v]+d);
                R.push(nv);
            }
        }
    }

    REP(i,0,Q) PR(D[X[i]]+D[Y[i]]);

    return 0;
}

/*



*/