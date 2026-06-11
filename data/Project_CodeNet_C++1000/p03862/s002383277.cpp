#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> b(n);
  for(int i = 0; i < n; i++) {
    b[i] = min(a[i], x);
  }
  for(int i = 0; i < n - 1; i++){
    if(b[i] + b[i + 1] > x){
      b[i + 1] -= (b[i] + b[i + 1]) - x;
    }
  }
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += a[i] - b[i];
  }

  cout << ans << endl;
  return 0;
}