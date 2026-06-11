#include <bits/stdc++.h>

using namespace std;

vector <int> g[100005];
int n;
int pred[100005];

void dfs(int u, int par, int h){
    pred[u]=par;
    if(u==n-1){
        int v=u;
        for(int i=0;i<(h-1)/2;i++){
            v=pred[v];
        }
        g[v].erase(remove(g[v].begin(),g[v].end(),pred[v]),g[v].end());
        g[pred[v]].erase(remove(g[pred[v]].begin(),g[pred[v]].end(),v),g[pred[v]].end());
        return;
    }
    for(auto v:g[u]){
        if(v!=par){
            dfs(v,u,h+1);
        }
    }
}

void dfssiz(int u, int par, int &siz){
    siz++;
    for(auto v:g[u]){
        if(v!=par){
            dfssiz(v,u,siz);
        }
    }
}

int main(){
    cin >> n;
    for(int i=0,u,v;i<n-1;i++){
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,-1,0);
    int siz0=0,sizn=0;
    dfssiz(0,-1,siz0);
    dfssiz(n-1,-1,sizn);
    if(siz0>sizn){
        cout << "Fennec" << endl;
    }
    else{
        cout << "Snuke" << endl;
    }
    return 0;
}