#include<bits/stdc++.h>
#define N 100005
using namespace std;
vector<int> g[N];
int n,m,a1,a2,a3;//a1 -- a single point ; a2 -- a binary graph ;a3 -- else
int vis[N];

bool DFS(int u,int col){
    vis[u]=col;bool ret=true;
    for(int i:g[u])
        if(vis[i]==0) ret&=DFS(i,col^1);
        else if(vis[i]==vis[u]) ret=false;
    return ret;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,f,t;i<=m;i++)
        scanf("%d%d",&f,&t),g[f].push_back(t),g[t].push_back(f);
    for(int i=1;i<=n;i++)
        if(vis[i]==0)
            if(g[i].size()==0) a1++;
            else if(DFS(i,2)) a2++;
            else a3++;
    cout<<1LL*a1*a1+a1*1LL*(n-a1)*2+(a2+a3)*1LL*(a2+a3)+a2*1LL*a2<<endl;
    return 0;
}