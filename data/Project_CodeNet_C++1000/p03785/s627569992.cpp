#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main(){
  ll N,C,K;
  cin>>N>>C>>K;
  vector<ll> T(N);
  for(int i(0);i<N;i++){
    cin>>T[i];
  }
  sort(T.begin(),T.end());
  int cnt(0);
  ll syupatsu = T[0];
  int ans(0);
  for(int i(0);i<N;i++){
    ll now = T[i];
    cnt++;
    if(i != 0 && now-syupatsu > K){
      cnt = 1;
      syupatsu = T[i];
      ans++;
    }
    if(cnt == C) {
      cnt = 0;
      syupatsu = T[i+1];
      ans++;
    }
  }
  if(cnt != 0) ans++;
  cout << ans << endl;
  return 0;
}


