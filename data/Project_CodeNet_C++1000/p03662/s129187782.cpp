#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<ll,ll> P;
const int xn=100001; vector<int> v[xn]; int pr[xn]; int ply[xn]; int ct[2];
int dfs(int from, int to){
  pr[to]=from;
  for(int nx:v[to]) {
    if (from == nx) continue;
    dfs(to, nx);
  }
}
int dfs2(int from, int to, int py, int en) {
  ct[py]++;
  for(int nx:v[to]) {
    if (from == nx) continue;
    else if (ply[nx] == en) continue;
    dfs2(to, nx, py, en);
  }
}
int main() {
  int n; cin>>n;
  for(int i=0;i<n-1;i++) {
    int a,b; cin>>a>>b; a--;b--;
    v[a].push_back(b); v[b].push_back(a);
  }
  dfs(-1,0);

  //for(int i=0;i<n;i++) cout<<pr[i]<<" "; cout<<endl;
  
  int pv=n-1;
  vector<int> v2;
  v2.push_back(pv);
  while(true) {
    pv=pr[pv];
    if (pv==-1) break;
    v2.push_back(pv);
  }

  //for(int x:v2) cout<<x<<" "; cout<<endl;
  reverse(v2.begin(), v2.end());

  fill(ply, ply+n, -1);
  ct[0]=ct[1]=0;
  int ii=0, jj=v2.size()-1;
  while(ii<jj) {
    ply[v2[ii]] = 0; ii++;
    ply[v2[jj]] = 1; jj--;
  }
  //for(int i=0;i<n;i++) cout<<ply[i]<<" "; cout<<endl;
  dfs2(-1, 0, 0, 1);
  ct[1] = n - ct[0];
  //cout<<ct[0]<<" "<<ct[1]<<endl;
  if (ct[0] <= ct[1]) cout<<"Snuke"<<endl;
  else cout<<"Fennec"<<endl;
}