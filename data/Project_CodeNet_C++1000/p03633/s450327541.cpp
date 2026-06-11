#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
  ll N;
  cin >> N;
  vector<ll> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }
  ll ans = T[0];
  for (int i = 1; i < N; i++) {
    ans = lcm(ans, T[i]);
  }
  cout << ans << endl;
  return 0;
}