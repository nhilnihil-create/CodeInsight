#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

struct edge{
  int to,we;
};
vector<vector<edge>> v(100);
vector<vector<int>> d(100,vector<int>(100,1e8));
set<P> st;

void dfs(int pos,int pre,int S,int G){
  if(pos == G)return ;
  for(auto nv : v[pos]){
    if(nv.to == pre)continue;
    if(d[S][G] == d[S][pos]+d[nv.to][G]+nv.we){
      int a = pos,b = nv.to;
      if(a > b)swap(a,b);
      st.insert({make_pair(a,b)});
      dfs(nv.to,pos,S,G);
    }
  }
}

int main(){
  
  int n,m;
  cin >> n >> m;
  rep(i,n)d[i][i] = 0;
  rep(i,m){
    int a,b,c;cin >> a >> b >> c;
    a--,b--;
    v[a].push_back({b,c});
    v[b].push_back({a,c});
    d[a][b] = d[b][a] = c;
  }
  rep(k,n)rep(i,n)rep(j,n)d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
  rep(i,n)for(int j = i+1;j < n;j++)dfs(i,i,i,j);
  int k = st.size();
  cout << m-k << endl;


  
  return 0;
}