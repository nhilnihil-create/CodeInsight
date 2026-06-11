#include <bits/stdc++.h>
using namespace std;
int a[100005];
vector<int> adjlist[100005];
int ans[100005];
bool cmp(int a, int b){
    return ans[a] > ans[b];
}
void dfs(int u){
    ans[u] = 0;
    for (auto v : adjlist[u]){
        dfs(v);
    }
    sort(adjlist[u].begin(),adjlist[u].end(),cmp);
    int ct = 1;
    for (auto v : adjlist[u]){
        //printf("%d -> %d: %d + %d\n",u,v,ans[v],ct);
        ans[u] = max(ans[u],ans[v]+ct++);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 2; i <= n; i++){
        scanf("%d",&a[i]);
        adjlist[a[i]].push_back(i);
    }
    dfs(1);
    printf("%d",ans[1]);
}
