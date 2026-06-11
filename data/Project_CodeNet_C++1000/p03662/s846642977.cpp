#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdio>

#include<vector>
using namespace std;
int n;
vector<int> g[233333];
int dist[2][233333],id;
void dfs(int idx,int par=-1){//树上dfs
    if(par!=-1){
        dist[id][idx]=dist[id][par]+1;
    }
    for(int i=0;i<g[idx].size();i++){
        if(g[idx][i]!=par){
            dfs(g[idx][i],idx);
        }
    }
    return;
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    id=0;
    dfs(0);//F距离每个点的距离
    id=1;
    dfs(n-1);//S距离每个点的距离
    int res=0;
    for(int i=0;i<n;i++){
        if(dist[0][i]<=dist[1][i]){//显而易见，比离谁进
            res++;
        }
    }
    if(res>=n/2+1){//F赢了
        puts("Fennec");
    }
    else{//不然就是S赢了
        puts("Snuke");
    }
    return 0;
}