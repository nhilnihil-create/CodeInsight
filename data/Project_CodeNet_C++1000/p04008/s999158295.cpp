#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n,pa[100005],k,ans;
vector<int>g[100005];
int dfs(int v,int p){
    int d=0;
    for(int i=0;i<g[v].size();i++){
        int u=g[v][i];
        if(u!=p){
            d=max(d,dfs(u,v)+1);
        }
    }
    if(v==0)return 0;
    if((d==k-1&&pa[v]!=0)||(pa[v]==0&&d==k)){
        ans++;
        return -1;
    }else return d;
}
int main(void){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",pa+i);
        pa[i]--;
        if(i==0){
            if(pa[i]!=0)ans++;
        }else g[pa[i]].push_back(i);
    }
    dfs(0,-1);
    printf("%d\n",ans);
}