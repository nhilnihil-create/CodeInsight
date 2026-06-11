#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

vector<vector<int> > g;
vector<int> depth;
vector<int> parent;
vector<int> save0, save1;

void dfs(int par, int curr, int d, int& cnt)
{
    save0[curr] = cnt; cnt++;
    parent[curr] = par;
    depth[curr] = d;
    int i;
    for (i = 0; i < (int)g[curr].size(); i++) {
        int next = g[curr][i];
        if (next == par) continue;

        dfs(curr, next, d+1, cnt);
    }
    save1[curr] = cnt;

    return;
}

void solve()
{
    int n;
    scanf("%d", &n);
    g.resize(n); depth.resize(n); parent.resize(n);
    save0.resize(n); save1.resize(n);
    int i;
    for (i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    dfs(-1, 0, 0, cnt);

    int d = depth[n - 1];
    int d2 = (d - 1) / 2;
    int curr = n - 1;
    for (i = 0; i < d2; i++) {
        curr = parent[curr];
    }
    int tmp = save1[curr] - save0[curr];
    if (n - tmp > tmp) {
        printf("Fennec\n");
    }
    else {
        printf("Snuke\n");
    }

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d%d", &T, &B);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

