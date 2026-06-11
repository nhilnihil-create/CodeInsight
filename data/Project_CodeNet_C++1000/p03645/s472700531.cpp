#include <bits/stdc++.h>
#define ll long long
using namespace std;
using Graph=vector<vector<int>>;

int main(){
  int n,m;
  cin>>n>>m;
  Graph G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }
  int seen[n+100]={};
  for(int x:G[0]){
    seen[x]++;
  }
  for(int x:G[n-1]){
    seen[x]++;
    if(seen[x]==2){
      cout<<"POSSIBLE"<<endl;
      return 0;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
}