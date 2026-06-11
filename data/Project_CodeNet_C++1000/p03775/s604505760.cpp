#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dig(ll s){
  ll answer =0;
  while (s!=0){
    s /= 10;
    answer++;
  }
  return answer;
}

int main() {
  ll N;
  cin >> N;
  ll ans = 1e10;
  
  for (ll i=1; i*i<=N; i++){
    if(N%i == 0){
      ll B = N/i;
      ll tans = max(dig(i), dig(B));
      ans = min(ans, tans);
    }
  }
  cout << ans << endl;
  
}