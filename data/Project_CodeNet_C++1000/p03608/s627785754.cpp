#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,m,R;
  cin >> n >> m >> R;
  vector<int>r(R);
  rep(i,0,R){cin >> r[i];r[i]--;}
  vector<vector<int>>d(n,vector<int>(n,1e9+7));
  rep(i,0,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    d[a][b] = d[b][a] = c;
  }
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  sort(r.begin(),r.end());
  int ans = 1e9+7;
  do {
    int tmp = 0;
    rep(i,0,R-1) tmp += d[r[i]][r[i+1]];
    ans = min(ans,tmp);
  } while (std::next_permutation(r.begin(), r.end()));
  cout << ans << endl;
}