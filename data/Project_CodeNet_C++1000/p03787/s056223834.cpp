#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " :: " << x << endl
#define _ << " " <<
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for (int i=(a);i>=(b);--i)

const int MX_N = 1e5+5;

int N, M;
vector<int> al[MX_N];

int col[MX_N];

bool rip;
void dfs(int u, bool c=0) {
    col[u] = c;
    for (int v : al[u]) {
        if (col[v] == -1) dfs(v,!c);
        else if (col[v] == col[u]) rip = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    FOR(i,1,M){
        int U, V; cin >> U >> V;
        al[U].push_back(V);
        al[V].push_back(U);
    }

    long long ans = 0;
    int p = 0, q =0, r=0;
    memset(col,-1,sizeof col);
    FOR(i,1,N) if (col[i] == -1){
        if (SZ(al[i]) == 0) ans += 2*(N-r)-1, ++r;
        else {
            rip = 0; dfs(i);
            if (rip) ++p;
            else ++q;
        }
    }

    //TRACE(ans _ p _ q);
    ans += 1LL*p*p + 1LL*p*q + 1LL*q*p + 2LL*q*q;
    cout << ans;
}

