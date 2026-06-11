#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,ll>;

int main(){
  int n;
  cin >> n;
  vector<vector<P>> v(n,vector<P>(0));
  for(int i=0; i<n-1; ++i){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    --a; --b;
    v[a].push_back(make_pair(b,c));
    v[b].push_back(make_pair(a,c));
  }
  int q, k;
  cin >> q >> k;
  --k;
  vector<ll> d(n,-1);
  queue<P> que;
  que.push(make_pair(k,0));
  while(!que.empty()){
    int x;
    ll dis;
    tie(x,dis) = que.front();
    que.pop();
    d[x] = dis;
    for(auto p:v[x]){
      if(d[p.first] != -1) continue;
      que.push(make_pair(p.first, dis+p.second));
    }
  }
  
  for(int i=0; i<q; ++i){
    int q1, q2;
    cin >> q1 >> q2;
    --q1; --q2;
    printf("%lld\n", d[q1] + d[q2]);
  }
}