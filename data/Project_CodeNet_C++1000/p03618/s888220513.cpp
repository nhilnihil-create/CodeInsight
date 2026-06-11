#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  string s;
  cin>>s;
  ll N = int(s.size());
  ll cnt[30] = {0};
  for(int i(0);i<N;i++){
    cnt[s[i]-'a']++;
  }
  ll ans(N*(N-1)/2+1);
  //cout << ans << endl;
  for(int i(0);i<30;i++){
    ans -= (cnt[i]*(cnt[i]-1)/2);
  }
  cout << ans << endl;
  return 0;
}
