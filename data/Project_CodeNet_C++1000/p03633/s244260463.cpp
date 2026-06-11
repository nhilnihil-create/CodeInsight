#include <bits/stdc++.h>
using namespace std;

#define ll long long 


ll gcd(ll a, ll b) {
  return a % b ? gcd(b, a % b) : b;
}


int main() {
  int N;
  cin >> N;
  
  vector<ll> time(N);
  for (int i = 0; i < N; i++) {
    cin >> time[i];
  }
  
  ll ans = time[0];
  for (int i = 0; i < N-1; i++) {
    ll LCM = time[i] * (time[i+1] / gcd(time[i], time[i+1]));
    ans = ans * (LCM / gcd(ans, LCM));
  }
  
  cout << ans << endl;
}