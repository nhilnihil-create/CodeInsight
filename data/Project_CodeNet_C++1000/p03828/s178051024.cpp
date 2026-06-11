#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;

vector<ll> v_prime;

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  
  for (ll a = 2; a*a <= n; a++) {
    if (n % a) continue;
    ll ex = 0;
    
    while (n % a == 0) {
      ex++;
      n /= a;
    }
    
    res.push_back({a, ex});
  }
  
  if (n != 1) res.push_back({n,1});
  
  return res;
}
  
  
int main() {
  int N;
  cin >> N;
  
  vector<ll> prime_v(1000, 0);
  
  for (ll i = 2; i <= N; i++) {
    vector<pair<ll, ll>> temp_factorize = prime_factorize(i);
    
    int t = temp_factorize.size();
    for (int j = 0; j < t; j++) {
      pair<ll, ll> p = temp_factorize[j];
      
      prime_v[p.first] += p.second; 
    }  
  }
  
  ll ans = 1;
  for (int i = 1; i < 1000; i++) {
    ans *= (prime_v[i] + 1);
    ans %= MOD;
  }
  
  cout << ans << endl;
  
  
}