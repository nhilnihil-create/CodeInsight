#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define N 100003
using namespace std;

vector<int> adj[N];
int a[N];
int n;

void dfs(int u,int fa){
    a[u] = 0;
    int v,l = adj[u].size();
    for(int i=0;i<l;++i){
        v = adj[u][i];
        if(v==fa) continue;
        dfs(v,u);
        a[u] ^= a[v]+1;
    }
}

inline void read(int &x){
    x = 0;
    char c = getchar();
    while(c<'0'||c>'9') c = getchar();
    while(c>='0'&&c<='9'){
        x = (x<<3)+(x<<1)+(c^48);
        c = getchar();
    }
}

int main(){
    int u,v;
    read(n);
    for(int i=1;i<n;++i){
        read(u),read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    printf(a[1]?"Alice\n":"Bob\n");
    return 0;
}