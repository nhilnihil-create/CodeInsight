#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); (i)--)
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;

int main(){
  int n; long w; cin >> n >> w;
  vector<int> v[4];
  long w0; int v0; cin >> w0 >> v0;
  v[0].push_back(v0);
  rep(i, n-1){
    int wi, vi; cin >> wi >> vi;
    v[wi-w0].push_back(vi);
  }
  int ans = 0;
  rep(i, 4) sort(v[i].begin(), v[i].end(), greater<int>());
  rep(i, (int)v[0].size()+1)rep(j, (int)v[1].size()+1)rep(k, (int)v[2].size()+1)rep(l, (int)v[3].size()+1){
    if(w0*(i+j+k+l)+j+2*k+3*l <= w){
      int vsum = 0;
      rep(m, i) vsum += v[0][m];
      rep(m, j) vsum += v[1][m];
      rep(m, k) vsum += v[2][m];
      rep(m, l) vsum += v[3][m];
      ans = max(ans, vsum);
    }
  }
  cout << ans << endl;
}