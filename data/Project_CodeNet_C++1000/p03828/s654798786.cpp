#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007;

bool isprime(int x) {
  int i;
  if(x < 2) return 0;
  else if(x == 2) return 1;
  if(x%2 == 0) return 0;
  for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
  return 1;
}

int main() {
  int n;
  cin >> n;
  ll ans = 1;
  for(int i = 2; i <= n; i++) {
    if(!isprime(i)) continue;
    ll res = 1;
    for(int j = i; j <= n; j++) {
      int k = j;
      int cnt = 0;
      while(k%i==0) {
        k /= i;
        cnt++;
      }
      res += cnt;
    }
    ans *= (ll)res;
    ans %= (ll)mod;
  }
  cout << ans << endl;
  return 0;
}