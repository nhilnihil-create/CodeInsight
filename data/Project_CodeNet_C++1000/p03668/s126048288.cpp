#include<bits/stdc++.h>
using namespace std;
#define N 100005
int sg[N];
vector<int> g[N];
int n;
void DFS(int u,int fr){
    for(int i:g[u])
        if(i!=fr)
            DFS(i,u),sg[u]^=sg[i];
    sg[u]+=u!=1;
}
int main(){
    scanf("%d",&n);
    for(int i=2,f,t;i<=n;i++) scanf("%d%d",&f,&t),g[f].push_back(t),g[t].push_back(f);
    DFS(1,0);
    puts(sg[1]==0? "Bob":"Alice");
    return 0;
}