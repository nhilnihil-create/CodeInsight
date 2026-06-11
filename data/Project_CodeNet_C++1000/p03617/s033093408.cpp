#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll q, h, s, d;
  cin >> q >> h >> s >> d;
  
  ll n;
  cin >> n;

  ll ans = 0;
  
  vector<ll> a = {q*8, h*4, s*2, d};
  sort(a.begin(), a.end());

  ans += a[0] * (n / 2);

  vector<ll> b = {q*4, h*2, s};
  sort(b.begin(), b.end());
  
  ans += b[0] * (n % 2);
  
  cout << ans << endl;

  return 0;
}
