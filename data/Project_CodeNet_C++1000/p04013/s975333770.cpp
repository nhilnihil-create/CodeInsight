#include <bits/stdc++.h>
using namespace std;
using um = unordered_map<int, long long>;
#define each(i, a) for (auto &&i : (a))

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> x(N);
  each(i, x) cin >> i;
  each(i, x) i -= A;
  function<um(int, int)> div_con = [&](int l, int r) {
    um ret;
    if (r - l == 1)
      ret[x[l]]++;
    else {
      int m = (l + r) / 2;
      um lm = div_con(l, m), rm = div_con(m, r);
      each(p, lm) ret[p.first] += p.second;
      each(p, rm) ret[p.first] += p.second;
      each(p, lm) each(q, rm) ret[p.first + q.first] += p.second * q.second;
    }
    return ret;
  };
  cout << div_con(0, N)[0] << endl;
}