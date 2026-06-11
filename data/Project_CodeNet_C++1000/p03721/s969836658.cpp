#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N, K;
  cin >> N >> K;
  
  vector<ll> num(100001, 0);
  for (int i = 0; i < N; i++){
    ll a, b;
    cin >> a >> b;
    num.at(a) += b;
  }
  
  ll pos = 0, ans = 0;
  while (pos < K){
    pos += num.at(ans);
    ans++;
  }
  
  cout << ans - 1 << endl;
}