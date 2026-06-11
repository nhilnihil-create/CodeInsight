#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> t(n+1); for(int i = 1;i<=n;i++) cin >> t[i];
  int m; cin >> m;
  vector<int> p(m+1),x(m+1); for(int i = 1;i<=m;i++) cin >> p[i] >> x[i];

  for(int i = 1;i<=m;i++){
    int ans = 0;
    for(int j = 1;j<=n;j++){
      if(p[i] != j) ans += t[j];
      else ans += x[i];
    }
    cout << ans << endl;
  }
  
  return 0;
}
