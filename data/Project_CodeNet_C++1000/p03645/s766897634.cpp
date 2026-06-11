#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> to[200010];
  rep(i,m){
    int a,b; cin>>a>>b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  queue<int> q;
  bool ans=0;
  for(auto x : to[1]){
    q.push(x);    
  }
  while(!q.empty()){
    int l=q.front(); q.pop();
    for(auto x : to[l]){
      if(x==n)ans=1;
    }
  }
  if(ans) cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}