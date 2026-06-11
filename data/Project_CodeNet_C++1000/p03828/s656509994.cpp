#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
vector<bool> ps(1000+1, true);

void sieve() {
  for(int i = 2; i*i <= 1000; i++) {
    if (ps.at(i)) {
      int c = i*2;
      while(c <= 1000) {
        ps.at(c) = false;
        c += i;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  sieve();
  map<int, int> mp;
  ll r = 1e9 + 7;
  reps(i, 2, n+1) {
    int t = i;
    reps(j, 2, 1000+1) {
      if (ps[j]) {
        while(t % j == 0) {
          mp[j]++;
          t /= j;
        }        
      }
    }
  }  
  ll ans = 1;
  for(auto it = mp.begin(); it != mp.end(); it++) {
    ans *= it->second + 1;
    ans %= r;
  }
  cout << ans << endl;
  return 0;
}