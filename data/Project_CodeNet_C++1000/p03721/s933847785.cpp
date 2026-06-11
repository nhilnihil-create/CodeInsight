#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N, K;
  cin >> N >> K;

  int max = 100001;
  
  vector<ll> tmp(max, 0);
  for (int i = 0; i < N; i++){
    ll a, b;
    cin >> a >> b;
    tmp.at(a) += b;
  }
  
  ll count = 0;
  for (int ans = 1; ans < max; ans++) {
    count += tmp[ans];
    if (count >= K) {
      cout << ans << endl;
      break;
    }
  }
  
  return 0;
}
