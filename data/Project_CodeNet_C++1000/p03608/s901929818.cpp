#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

int main() {
  int N,M,R,a,b,c;
  cin >> N >> M >> R;
  vector<int> r(R);
  rep(i,R) {
    cin >> r[i];
    r[i]--;
    }
  vector<vector<ll>> cost(N,vector<ll>(N,200000000000));
  // vector<vector<vector<int>>> g(N);
  rep(i,M) {
    cin >> a >> b >> c;
    a--;b--;
    cost[a][b] = cost[b][a] = c;
  }

  rep(k,N)rep(i,N)rep(j,N){
    chmin(cost[i][j], cost[i][k] + cost[k][j]);
  }

  sort(r.begin(),r.end());

  ll res=LONG_LONG_MAX/100,tmp;
  while (next_permutation(r.begin(),r.end())) {
    tmp = 0;
    rep(i,r.size()-1) tmp+=cost[r[i]][r[i+1]];
    chmin(res,tmp);
  }
  cout << res << endl;
} 