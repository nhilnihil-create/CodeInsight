#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2001;
vector<int> G[N];
int n,k;

int sub[N][N],d[N][N];
int a[N],b[N];
int  root;
void dfs(int x,int fa) {
    d[root][x] = d[root][fa]+1;
    sub[root][x] = 1;
    for(auto y:G[x]) {
        if(y==fa) continue;
        dfs(y,x);
        sub[root][x] += sub[root][y];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<n;i++) {
        cin>>a[i]>>b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    for(int i=1;i<=n;i++) {
        root = i;
        d[root][0] = -1;
        dfs(i,0);
    }
    int ans = n;
    if(k&1) {
        for(int i=1;i<n;i++) {
            int u=a[i],v=b[i];
            int tmp = 0;
            for(int j=1;j<=n;j++) {
                int dist = min(d[u][j],d[v][j]);
                if(dist>k/2) tmp++;
            }
            ans = min(ans,tmp);
        }
    }else {
        for(int i=1;i<=n;i++) {
            int tmp = 0;
            for(int j=1;j<=n;j++) {
                if(d[i][j]>k/2) tmp++;
            }
            ans = min(ans,tmp);            
        }
    }
    cout<<ans<<endl;
    return 0;
}


