#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

bool is_prime(int n) {
  for(int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
vector<bool> sieve(int n) {
  vector<bool> vec(n+1, true);
  vec[0] = false;
  vec[1] = false;
  for(int i = 2; i*i <= n; i++) {
    if (is_prime(i)) {
      int x = i*2;
      while(x <= n) {
        vec[x] = false;
        x += i;
      }
    }
  }
  return vec;
}
  
int main()
{
  int n;
  cin >> n;
  map<int, int> mp;
  vector<bool> ps = sieve(n);
  ll r = 1e9+7;
  for (int i = 2; i <= n; i++) {
    int x = i;
    rep(j, (int)ps.size()) {
      if (ps[j]) {
        while(x % j == 0) {
          x /= j;
          mp[j]++;
        }
      }
    }
  }
  ll ans = 1;
  for (auto m = mp.begin(); m != mp.end(); m++) {
    ans *= (m->second + 1);
    ans %= r;
  }
  cout << ans << endl;
  return 0;
}