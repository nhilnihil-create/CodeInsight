#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll choose[51][51];
 
// vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  return s;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> lv(n);
  for (int i = 0; i < n; ++i) {
    cin >> lv[i];
  }
  sort(lv.begin(), lv.end(), greater<ll>());


  // nCrの事前計算
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (i == j || j == 0) {
        choose[i][j] = 1;
        continue;
      }
      if (i > 0) choose[i][j] += choose[i-1][j];
      if (j > 0) choose[i][j] += choose[i-1][j-1];
    }
  }
  ll sum = 0;
  ll last = -1;
  int count = 0;
  int start = -1;
  for (int i = 0; i < n; ++i) {
    ll v = lv[i];
    if (v != last) {
      if (i >= a) break;
      count = 0;
      start = i;
    }
    ++count;
    last = v;
    if (i < a) {
      sum += last;
    }
  }
  double ans_avg = (double) sum / (double)a;
  printf("%f\n", ans_avg);

  // cout << count << " " << start << " " << last << endl;
  ll ans = 0;
  for (int i = 0; i < min(count, b-a+1); ++i) {
    if (start > 0 && i > 0) break;
    if (a-start+i > count) break;
    ll c = choose[count][a-start+i];
    // cout << i << " " << count << " " << a-start+i << " " << c << endl;
    ans += c;
  }
  cout << ans << endl;
}

