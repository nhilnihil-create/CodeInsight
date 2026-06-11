#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;
vector<bool> seen;

void f(const graph &g,int s,vector<int> &ans){
  for(auto nx:g[s]){
    if(seen[nx]) continue;
    seen[nx]= true;
    ans.push_back(nx);
    f(g,nx,ans);
    break;
  }
}

int main() {
  int N,M;
  cin>>N>>M;
  graph g(N);
  for(int i = 0; i < M; i++){
    int x,y;
    cin>>x>>y;
    g[x-1].push_back(y-1);
    g[y-1].push_back(x-1);
  }
  seen.assign(N,false);
  vector<int> ansa,ansb;
  seen[0]=true;
  f(g,0,ansa);
  f(g,0,ansb);
  reverse(ansb.begin(),ansb.end());
  cout<<ansa.size()+1+ansb.size()<<endl;
  for(auto x:ansb) cout<<x+1<<" ";
  cout<<1<<" ";
  for(auto x:ansa) cout<<x+1<<" ";
  cout<<endl;
}