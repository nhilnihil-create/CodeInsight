#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX;
const ll MOD = 998244353;

int main() {
  int N,M;cin >> N >> M;
  vector<vint> g(N);
  repeat(i,M){
    int a,b;cin >> a >> b;a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int Q;cin >> Q;
  vint v(Q),d(Q),c(Q);
  repeat(q,Q){
    cin >> v[q] >> d[q] >> c[q];v[q]--;
  }
  vint ans(N,0);
  vint vd(N,-1);
  for(int q=Q-1;q>=0;q--){
    queue<Pii> que;
    que.push({v[q],d[q]});
    while(!que.empty()){
      Pii p = que.front();
      que.pop();
      if(vd[p.first]>=p.second) continue;
      vd[p.first] = p.second;
      if(ans[p.first]==0) ans[p.first] = c[q];
      for(int u:g[p.first]){
        que.push({u,p.second-1});
      }
    }
  }
  repeat(i,N){
    cout << ans[i] << endl;
  }
  return 0;
}
