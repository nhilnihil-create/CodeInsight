#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

const int MX_N = 1e5+5;

int N, K;
vector<int> al[MX_N];

ii dfs(int u, int p) {
    ii ret = ii(0,0);
    for (int v : al[u]) if (v != p) {
        ii x = dfs(v,u);
        if (x.sc+1 == K && u != 1) ++ret.fi;
        else ret.sc = max(ret.sc, x.sc+1);
        ret.fi += x.fi;
    }
    return ret;
}

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    int add = 0;
    FOR(i,1,N){
        int A; cin >> A;
        if (i > 1) al[A].push_back(i);
        else if (A != 1) ++add;
    }
    cout << dfs(1,-1).fi + add;
}

