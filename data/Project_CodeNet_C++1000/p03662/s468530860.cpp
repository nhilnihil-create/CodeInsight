#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;

int n;
vector<int> edge[100010];
vector<int> memo_b;
vector<int> memo_w;

//color = false = black, color = true = white
void dfs(int x, int vis, bool color) {
    if (color) {
        if (memo_w[x] != -1) return;
        else memo_w[x] = vis;
    }
    else {
        if (memo_b[x] != -1) return;
        else memo_b[x] = vis;
    }
    for (auto&& e: edge[x]) dfs(e, vis+1, color);
    return;
}

int main(int argc, char const *argv[]) {
    cin >> n;
    memo_b.resize(n, -1); memo_w.resize(n, -1);
    REP(i,n-1) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(0, 0, false);
    dfs(n-1, 0, true);
    int cntb = 0; int cntw = 0;
    //REP(i,n) printf("memo_b[%d] = %d, memo_w[%d] = %d\n", i, memo_b[i], i, memo_w[i]);
    REP(i,n) {
        if (memo_b[i] <= memo_w[i]) cntb++;
        else cntw++;
    }
    if (cntb > cntw) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}