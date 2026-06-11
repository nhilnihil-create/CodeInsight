#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)
map<int,vector<int>> g;
void remove(int u,int v) {
  rep(i,g[u].size()) {
    if(g[u][i]==v) {
      g[u].erase(g[u].begin()+i);
      return;
    }
  }
}

int treeSize(int s) {
  set<int> visited;
  visited.insert(s);
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    int v=q.front();
    q.pop();
    visited.insert(v);
    for(auto& u : g[v]) {
      if(visited.find(u)==visited.end()) {
        q.push(u);
      }
    }
  }
  return visited.size();
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  int n;
  cin>>n;
  rep(i,n-1) {
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> prev(n+1);
  queue<int> q;
  q.push(1);
  prev[1]=-1;
  while(!q.empty()) {
    int v=q.front();
    q.pop();
    for(auto& u : g[v]) {
      if(prev[u]==0) {
        prev[u]=v;
        q.push(u);
      }
    }
  }
  vector<int> path;
  {
    int v=n;
    while(v!=-1) {
      path.push_back(v);
      v=prev[v];
    }
  }
  reverse(path.begin(),path.end());
  // for(auto& u : path) {
  //   cout << u << " " ;
  // }
  int u=path[(path.size()-1)/2],v=path[(path.size()-1)/2+1];
  remove(u,v);
  remove(v,u);
  if(treeSize(1)>treeSize(n)) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
  return 0;
}
