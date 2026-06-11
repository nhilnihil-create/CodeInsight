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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll minigcd;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(i > 0) {
      minigcd = gcd(minigcd, a[i]);
    } else {
      minigcd = a[i];
    }
  }

  if(k <= *max_element(a.begin(), a.end()) && k % minigcd == 0) {
    cout << "POSSIBLE\n";
  } else {
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}