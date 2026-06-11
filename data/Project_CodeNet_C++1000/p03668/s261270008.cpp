#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
vector<int> e[1010101];
int n,sg[1010101],u,v;
void dfs(int u,int faa){
    sg[u]=0;
    for (auto v:e[u]){
        if (v==faa) continue;
        dfs(v,u);
        sg[u]^=sg[v]+1;
    }
}
int main(){
    n=read();
    for (int i=1;i<n;++i){
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    puts(sg[1]?"Alice":"Bob");
}