#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=2005;
const double eps=1e-7;

int n,m;
vector<pair<int,int>> f;
vector<int> edge[MAXN];
int dep[MAXN];

void dfs(int u,int fa){
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if (v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int a,b; scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
        f.push_back(make_pair(a,b));
    }
    int ans=n;
    if (m%2==0){
        for(int i=1;i<=n;i++){
            dep[i]=0; dfs(i,0);
            int cnt=0;
            for(int j=1;j<=n;j++){
                if (dep[j]>m/2) cnt++;
            }
            ans=min(ans,cnt);
        }
    } else{
        for(int i=0;i<n-1;i++){
            int a=f[i].first,b=f[i].second;
            dep[a]=0; dfs(a,b);
            dep[b]=0; dfs(b,a);
            int cnt=0;
            for(int j=1;j<=n;j++){
                if (dep[j]>m/2) cnt++;
            }
            ans=min(ans,cnt);
        }
    }
    printf("%d\n",ans);
    return 0;
}