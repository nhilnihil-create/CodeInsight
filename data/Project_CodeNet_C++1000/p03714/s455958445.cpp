#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> a(3*n); REP(i, 3*n) cin >> a[i];
  priority_queue<int, vector<int>, greater<int> > left;
  long long tmp = 0;
  REP(i, n) {
    left.push(a[i]);
    tmp += a[i];
  }
  vector<long long> left_sum(n+1);
  left_sum[0] = tmp;
  REP(i, n) {
    if (left.top() < a[n+i]) {
      tmp -= left.top();
      left.pop();
      tmp += a[n+i];
      left.push(a[n+i]);
    }
    left_sum[i+1] = tmp;
  }
  reverse(ALL(a));
  priority_queue<int> right;
  tmp = 0;
  REP(i, n) {
    right.push(a[i]);
    tmp += a[i];
  }
  vector<long long> right_sum(n+1);
  right_sum[0] = tmp;
  REP(i, n) {
    if (right.top() > a[n+i]) {
      tmp -= right.top();
      right.pop();
      tmp += a[n+i];
      right.push(a[n+i]);
    }
    right_sum[i+1] = tmp;
  }
  long long ans = -LINF;
  REP(i, n+1) ans = max(ans, left_sum[i] - right_sum[n-i]);
  cout << ans << '\n';
  return 0;
}
