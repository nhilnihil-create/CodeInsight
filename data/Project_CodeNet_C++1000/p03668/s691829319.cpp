#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN=100005;

int n;
int sg[MAXN];
vector<int> E[MAXN];

void dfs(int u,int fa=0){
    sg[u]=0;
    for(int i=0;i<(int)E[u].size();i++){
        int v=E[u][i];
        if(v==fa) continue;
        dfs(v,u);
        sg[u]^=(sg[v]+1);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1);
    if(sg[1]) puts("Alice");
    else puts("Bob");
}
