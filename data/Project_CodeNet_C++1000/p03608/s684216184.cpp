#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

const int INF = 1001001001;

int main(){
  int n, m, R;
  cin >> n >> m >> R;
  vector<int> r(R);
  rep(i, R){
    int a;
    cin >> a;
    a--;
    r.at(i) = a;
  }
  vector<vector<int>> gr(n, vector<int>(n, INF));
  rep(i, m){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    gr.at(a).at(b) = c;
    gr.at(b).at(a) = c;
  }
  rep(i, n) gr.at(i).at(i) = 0;

  rep(k, n)rep(i, n)rep(j, n){
    gr.at(i).at(j) = min(gr.at(i).at(j), gr.at(i).at(k) + gr.at(k).at(j));
  }

  sort(r.begin(), r.end());
  ll ans = 1e18;
  do{
    ll add = 0;
    int now = r.at(0);
    rep2(i, 1, R){
      int nx = r.at(i);
      add += gr.at(now).at(nx);
      now = nx;
    }
    // cerr << add << endl;
    ans = min(ans, add);
  }while(next_permutation(r.begin(), r.end()));
  cout << ans << endl;
  return 0;
}