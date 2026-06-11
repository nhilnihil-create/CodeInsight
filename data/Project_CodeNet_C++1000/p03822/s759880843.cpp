#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int n, a[N], dep[N];
int head[N], nex[N], to[N], size;
vector<int> ord[N];
void add(int x, int y){
    to[++size] = y;
    nex[size] = head[x];
    head[x] = size;
}
void dfs(int u){
    int res = 0;
    for(int i = head[u];i;i = nex[i]){
        int v = to[i];
        dfs(v);
        ord[u].push_back(dep[v]);
    }
    sort(ord[u].begin(), ord[u].end(), greater<int>());
    int sz = ord[u].size();
    for(int i = 0;i < sz; i++){
        dep[u] = max(dep[u], i + 1 + ord[u][i]);
    }
}
int main(){
    cin>>n;
    for(int i = 2;i <= n; i++){
        scanf("%d", &a[i]);
        dep[a[i]]++;
        add(a[i], i);
    }
    dfs(1);
    cout<<dep[1]<<endl;
    return 0;
}
