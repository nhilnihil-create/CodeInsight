#include<bits/stdc++.h>
using namespace std;
const int nmax=100005;
vector<vector<int>> g(nmax);
int f(int s){
  int res=g[s].size();
  vector<int> v;
  for(int i=0;i<g[s].size();i++){
    v.push_back(f(g[s][i]));
  }
  sort(v.begin(),v.end(),greater<int>());
  for(int i=0;i<g[s].size();i++){
    res=max(res,v[i]+i+1);
  }
  return res;
}
int main(){
  int n;cin >> n;
  for(int i=1;i<n;i++){
    int a;cin >> a;
    a--;
    g[a].push_back(i);
  }
  cout << f(0) << endl;
}