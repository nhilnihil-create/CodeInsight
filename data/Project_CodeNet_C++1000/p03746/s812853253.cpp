#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> g[n+1];
  vector<bool> u(n+1,false);
  int a, b;
  rep(i,m){
    cin >> a >> b;
    g[a].push_back(b); g[b].push_back(a);
  }
  vector<int> t; vector<int> s;
  t.push_back(a); s.push_back(b);
  u[a] = true; u[b] = true;
  int na = a, nb = b;
  while(true){
    int p = -1;
    rep(i,g[na].size()){
      if(!u[g[na][i]]) {
        p = g[na][i];
        u[p] = true;
        t.push_back(p);
        na = p;
      }
    }
    if(p != -1) continue;
    rep(i,g[nb].size()){
      if(!u[g[nb][i]]) {
        p = g[nb][i];
        u[p] = true;
        s.push_back(p);
        nb = p;
      }
    }
    if(p == -1) break;
  }
  reverse(t.begin(),t.end());
  cout << t.size() + s.size() << endl;
  rep(i,t.size()) cout << t[i] << " ";
  rep(i,s.size()) cout << s[i] << " ";
  cout << endl;
  return 0;
}