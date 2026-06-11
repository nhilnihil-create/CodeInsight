 // ===================================
//   author: M_sea
//   website: http://m-sea-blog.com/
// ===================================
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define re register
using namespace std;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

const int N=2000+10;

int n,k;
vector<int> E[N];

int tot;
inline void dfs(int u,int fa,int dep) {
    if (dep>k/2) ++tot;
    for (re int v:E[u])
        if (v!=fa) dfs(v,u,dep+1);
}

int main() {
    n=read(),k=read();
    for (re int i=1;i<n;++i) {
        int u=read(),v=read();
        E[u].push_back(v),E[v].push_back(u);
    }
    int ans=2e9;
    if (k&1) {
        for (re int u=1;u<=n;++u)
            for (re int v:E[u])
                tot=0,dfs(u,v,0),dfs(v,u,0),ans=min(ans,tot);
    } else {
        for (re int u=1;u<=n;++u)
            tot=0,dfs(u,0,0),ans=min(ans,tot);
    }
    printf("%d\n",ans);
    return 0;
}
