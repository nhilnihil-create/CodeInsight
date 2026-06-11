#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define read        freopen("in.txt", "r", stdin)
#define write       freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second
#define MP make_pair

typedef long long ll;
typedef pair<int,int> pii;

const int M = 998244353 ;
const int MAX = (2e5) + 10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, xl, yl, jo, ja;
vector<int> mat[MAX];

void dfs(int p,int pa,int lev) {
    if(lev <= xl) { jo++; }
    if(lev <= yl) { ja++; }

    for(int x: mat[p]) {
        if(x == pa) { continue; }
        dfs(x, p, lev + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    //read;
    //write;
    int u, v, k;

    cin >> n >> k;
    FOR(i,1,n-1) {
        cin >> u >> v;
        mat[u].PB(v);
        mat[v].PB(u);
    }

    int prin = 0;

    xl = k / 2; yl = k - xl;
    FOR(p,1,n) {
        vector<pii> vovo;

        for(int x: mat[p]) {
            jo = ja = 0;
            dfs(x, p, 1);
            vovo.PB( {ja, jo} );
        }

        sort(vovo.begin(), vovo.end(), [](pii x,pii y) {
                return (x.F - x.S) > (y.F - y.S);
             });

        int rt = 1, fc = true;
        for(pii X: vovo) {
            rt += (fc ? X.F : X.S);
            fc = false;
        }
        prin = max(prin, rt);
    }

    cout << n - prin << endl;
    return 0;
}

