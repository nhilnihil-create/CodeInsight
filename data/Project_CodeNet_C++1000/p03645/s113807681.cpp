#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e5+5;
#define mod 1000000007
 
int n, m;
set<int> adj[mxn];
bool vis[mxn]; 

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    bool f=false;
    for(auto t: adj[1]){
        if(adj[t].count(n))f=true;
    }
    if(f)cout<<"POSSIBLE";
    else cout<<"IMPOSSIBLE";
}