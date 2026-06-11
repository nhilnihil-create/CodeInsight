#include <bits/stdc++.h>
#define N 100050
#define INF (1<<29)
using namespace std;
inline int rd() {
    int x=0,f=1;char ch=getchar();
    while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}

int a[N],b[N],n,k,tot;
vector<int> E[N];

void dfs(int u,int f,int d) {
    if (d > k/2) return ;
    tot++;
    for (int i=0;i<(int)E[u].size();i++) {
        int v = E[u][i];
        if (v == f) continue;
        dfs(v,u,d+1);
    }
}

int main() {
    n = rd(), k = rd();
    for (int i=1;i<n;i++) {
        int u = rd(), v = rd();
        a[i] = u, b[i] = v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int ans = INF;
    if (k%2 == 0) {
        for (int i=1;i<=n;i++) {
            tot = 0;
            dfs(i, i ,0);
            ans = min(ans, n - tot);
        }
    } else {
        for (int i=1;i<n;i++) {
            tot = 0;
            dfs(a[i], b[i], 0);
            dfs(b[i], a[i], 0);
            ans = min(ans, n - tot);
        }
    }

    cout << ans << endl;
    return 0;
}