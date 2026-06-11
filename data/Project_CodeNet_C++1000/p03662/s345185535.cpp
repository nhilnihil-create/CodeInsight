#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdio>

#include<vector>
using namespace std;
bool flag=false;
vector<int> v[233333];
vector<int> way;
bool vis[233333];
bool visited[233333];
int n;
int m;
int l,r;
bool dfs_find_way(int a){
    vis[a]=true;
    way.push_back(a);
    if(a==n){
        return true;
    }
    for(int i=0;i<v[a].size();i++){
        if(!vis[v[a][i]]){
            if(dfs_find_way(v[a][i])){
                return true;//true说明走到了
            }
        }
    }
    way.pop_back();
    return false;//false说明没走到
}
int dfs_get_ans(int a,int num=0){//结点累计
    visited[a]=true;
    for(int i=0;i<v[a].size();i++){
        if(!visited[v[a][i]]){
            num=dfs_get_ans(v[a][i],num+1);
        }
    }
    return num;
}
int main(){
    cin>>n;
    m=n-1;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs_find_way(1);
///*
    for(int i=0;i<way.size();i++){
        visited[way[i]]=true;
//  cout<<way[i]<<" ";
    }
//*/
//puts("1");
    for(int i=0;i<(way.size()+1)/2;i++){
        l+=dfs_get_ans(way[i],0);
    }
    for(int i=(way.size()+1)/2;i<way.size();i++){
        r+=dfs_get_ans(way[i],0);
    }
    if(l>r){
        puts("Fennec");
        return 0;
    }
    else if(l<r){
        puts("Snuke");
        return 0;
    }
    else{
        if(way.size()%2==0){
            puts("Snuke");
            return 0;
        }
        else{
            puts("Fennec");
            return 0;
        }
    }
    return 0;
}
