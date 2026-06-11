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
    ll N, M;
    cin >> N >> M;
    mat G(N);
    REP(i,0,M) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    queue<ll> Q;
    vec D(N, INF);
    Q.push(0);
    D[0] = 0;
    while(!Q.empty()) {
        ll v = Q.front(); Q.pop();
        FORR(nv,G[v]) {
            if(D[nv] > D[v] + 1) {
                D[nv] = D[v] + 1;
                Q.push(nv);
            }
        }
    }

    if(D[N-1] <= 2) PR("POSSIBLE");
    else PR("IMPOSSIBLE");



    return 0;
}

/*



*/