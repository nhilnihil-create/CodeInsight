#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[100005];
int a[100005];
int d[100005];
int mx[100005];
int ans = 0;
int n,k;
void dfs(int u){
    mx[u] = 0;
    for (auto v : adjlist[u]){
        d[v] = d[u]+1;
        dfs(v);
        //printf("%d ->%d: %d %d\n",u,v,d[v],mx[v]);
        if (mx[v] == k && u != 1){
            ans++;
        }
        else{
            mx[u] = max(mx[u],mx[v]);
        }
    }
    mx[u]++;
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        if (i == 1){
            if (a[i] != 1){
                ans++;
            }
        }
        else adjlist[a[i]].push_back(i);
    }
    d[1] = 0;
    dfs(1);
    printf("%d",ans);
}
