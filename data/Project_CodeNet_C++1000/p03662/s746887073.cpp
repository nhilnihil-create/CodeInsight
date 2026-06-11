#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
int dist = 0;
int disttravelled;
bool found = false;
int foundcount;
int col[MAXN];
bool visited[MAXN];
vector<int> v1[MAXN];
int n;
void dfs(int curr){
    visited[curr] = true;
    col[curr] = 1;

    if(curr!=1){
        dist++;
    }
    if(curr == n){

        found =true;
        return;
    }
    for(int x:v1[curr]){
        if(!visited[x]){

            dfs(x);
            if(found){
                return;
            }
            if(curr == 1){
                dist = 0;
            }
        }
    }
    col[curr] = 0;
    dist--;
}
void dfs2(int curr,int par){
   
    foundcount++;
    for(int x:v1[curr]){
        if(x==par){
            continue;
        }
        if(col[x] == 1){
            disttravelled++;
            if(disttravelled>dist){
                continue;
            }
        }
        dfs2(x,curr);
    }

}
int main(){

    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    dfs(1);
    
    dist/=2;
   
    dfs2(1,1);
    
    if(foundcount>(n/2)){
        cout<<"Fennec"<<endl;
    }else{
        cout<<"Snuke"<<endl;
    }
}
