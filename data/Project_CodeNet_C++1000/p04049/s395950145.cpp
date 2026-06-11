#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std; typedef long long ll; const int INF=1e9+7;
typedef pair<int,int> P;
const int mx=2000; vector<vector<int>> v(mx);
vector<vector<int>> d(mx, vector<int>(mx)); int n,k; vector<int> era(mx);

void dfs(int id, int from, int to, int len) {
  d[id][to]=len;
  if (len > k) era[id]++, era[to]++;
  for(int x:v[to]) {
    if (x == from) continue;
    dfs(id,to,x,len+1);
  }
}
int main() {
  if (mx != 2000) cerr<<"MXMXMXMXMXMx"<<endl;
  cin>>n>>k;
  for(int i=0;i<n-1;i++) {
    int a,b; cin>>a>>b; a--; b--; v[a].push_back(b); v[b].push_back(a);
  }
  for(int i=0;i<n;i++) dfs(i,-1,i,0);
  set<P, greater<P>> s;
  for(int i=0;i<n;i++) {
    if (era[i]) s.insert({era[i],i});
  }
  //for(int i=0;i<n;i++) cout<<era[i]<<" "; cout<<endl;
  int an=0;
  while(!s.empty()) {
    auto it=s.begin();
    int w=(*it).first;
    int t=(*it).second;
    //cout<<w<<" "<<t<<endl;
    s.erase({w,t});
    if (w<=0) continue;
    //cout<<t<<endl;
    an++;
    set<P, greater<P>> s2;
    for(P x:s) {
      if (d[t][x.second] > k) s2.insert({x.first-2,x.second});
      else s2.insert(x);
    }
    s=s2;
  }
  cout<<an<<endl;
}