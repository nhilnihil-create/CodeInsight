#include<vector>
#include<iostream>
using namespace std;
#define df 0
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long int li;

int dfs(const vector<vector<int>>& adj,int a=0,int seen=-1){
  int s=0;
  for(int v:adj.at(a)){
    if(v==seen)continue;
    s^=dfs(adj,v,a)+1;
  }
  return s;
}

int main(){
  if(df) printf("*debug mode*\n");
  int n; cin >>n;
  vector<vector<int>> adj(n);
  rep(i,n-1){
    int x,y; cin >>x >>y; x--; y--;
    adj.at(x).push_back(y);
    adj.at(y).push_back(x);
  }
  int ans=dfs(adj);
  cout << (dfs(adj)?"Alice":"Bob");
}

/// confirm df==0 ///
