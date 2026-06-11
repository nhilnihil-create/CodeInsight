#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,k; cin >> n >> k;
  vector<int> l(n); rep(i,n) cin >> l[i];
  sort(l.begin(),l.end());
  reverse(l.begin(),l.end());

  int ans = 0;
  rep(i,k) ans += l[i];

  cout << ans << endl;
  
  return 0;
}
