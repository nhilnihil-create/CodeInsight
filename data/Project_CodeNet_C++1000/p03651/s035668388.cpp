#include <iostream>
 
using namespace std;
typedef long long ll;
 
const ll MAXN = 1e5+10;
 
ll n, k;
ll arr[MAXN];
 
ll gcd(ll x, ll y) {
  if (x < y) {
    swap(x, y);
  }
  if (y == 0) {
    return x;
  }
  return gcd(y, x % y);
}
 
void solve() {
  ll d = arr[0];
  for (int i=0;i<n;i++) {
    d = gcd(d, arr[i]);
  }
  for (int i=0;i<n;i++) {
    if (k <= arr[i] && (k - arr[i]) % d == 0) {
      cout<<"POSSIBLE";
      return;
    }
  }
  cout<<"IMPOSSIBLE";
}
 
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  solve();
  return 0;
  
}