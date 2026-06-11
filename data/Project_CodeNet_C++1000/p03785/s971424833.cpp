#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
typedef long long ll;
const int inf = 100100100;

int main(){
  ll n,c,k;
  cin >> n >> c >> k;
  vector<int> t(n);
  rep(i,n) cin >> t[i];
  sort(t.begin(),t.end());
  
  ll ans = 0;
  ll cnt = 0;
  ll init;
  rep(i,n){
    if(cnt == 0 || cnt == c) {
      init = t[i]+k;
      cnt=1;
      ans++;
    }
    else if(t[i]<=init) cnt++;
    else {
      cnt = 1;
      ans++;
      init = t[i]+k;
    }
  }
  cout << ans << endl;
}
