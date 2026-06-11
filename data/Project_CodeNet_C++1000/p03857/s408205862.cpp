#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
using namespace std;

const int MAXN=2e5+5;

int n,k,l;
int co[MAXN],ans[MAXN],vis[MAXN];
vector<int> E[MAXN],G[MAXN];
stack<int> st;
map<int,int> sum;

void dfs(int u,int f){
    co[u]=f;
    for(int i=0;i<(int)E[u].size();i++){
        int v=E[u][i];
        if(co[v]) continue;
        dfs(v,f);
    }
}

void dfs2(int u){
    vis[u]=1;
    sum[co[u]]++;
    st.push(u);
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(vis[v]) continue;
        dfs2(v);
    }
}

int main(){
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=k;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    for(int i=1;i<=l;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ncnt=0;
    for(int i=1;i<=n;i++){
        if(co[i]) continue;
        ncnt++;
        dfs(i,ncnt);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        sum.clear();
        dfs2(i);
        while(!st.empty()){
            int h=st.top(); st.pop();
            ans[h]=sum[co[h]];
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
}
