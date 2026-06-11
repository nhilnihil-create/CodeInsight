#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define ll long long
using namespace std;
const int MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> sum(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll cnt = 1;
  for (ll i = 0; i < a.size(); i++) {
    if (i != 0) {
      sum[i] += sum[i - 1] + a[i];
    } else {
      sum[i] = a[i];
    }
  }
  for (ll i = n - 2; i >= 0; i--) {
    if (a[i] * 2 >= a[n - 1]) {
      cnt++;
    } else {
      if (sum[i] * 2 >= a[i + 1]) {
        cnt++;
      } else {
        break;
      }
    }
  }
  cout << cnt << endl;
}