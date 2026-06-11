#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N,M;cin >> N >> M;
  ll Mhalf = M/2;
  ll ans = min(Mhalf,N);
  N -= ans;
  M -= ans*2;
  ans += M/4;
  cout << ans << endl;
}