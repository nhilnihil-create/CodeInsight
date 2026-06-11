#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl

int n;
vector<int> G[maxn];
bool mark[maxn];
int from[maxn], sz[maxn];

void addedge(int u, int v) {
    G[u].push_back(v);
}

void dfs(int id, int fa) {
    sz[id] = 1;
    for (auto v: G[id]) {
        if (v == fa) continue;
        dfs(v, id);
        sz[id] += sz[v];
        from[v] = id;
    }
}

vector<int> ve;

int main() {
    //freopen(".in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    mark[n] = true;
    dfs(1, -1);
    int pos = n;
    while (pos) {
        ve.push_back(pos);
        pos = from[pos];
    }
    reverse(ve.begin(), ve.end());
    int len = ve.size();
    int A, B;
    if (len & 1) {
        A = sz[ve[(int)ve.size() / 2 + 1]];
        B = n - A;
    } else {
        A = sz[ve[(int)ve.size() / 2]];
        B = n - A;
    }
    if (A + 1 <= B) puts("Fennec");
    else puts("Snuke");
    return 0;
}
