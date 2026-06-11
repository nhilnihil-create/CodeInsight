#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); ++i)
#define repf(i, from, to) for (int i = (from); i < (to); ++i)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int secnd_start_time = max(a, c);
  int first_end_time = min(b, d);

  int double_time = first_end_time - secnd_start_time;

  cout << max(double_time, 0) << endl;
}