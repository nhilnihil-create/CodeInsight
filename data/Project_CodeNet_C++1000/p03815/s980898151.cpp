#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ll x;
  cin >> x;
  ll ans = x/11;
  x -= ans*11;
  ans *= 2;
  if(x>=1 && x<=6) ans++;
  if(x>=7) ans += 2;
  cout << ans << endl; 
  return 0;
}