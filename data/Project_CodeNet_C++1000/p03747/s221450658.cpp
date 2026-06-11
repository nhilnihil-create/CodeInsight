#include <bits/stdc++.h>
using namespace std;

long long n, l, t, now, cnter = 0, x, w;
vector<long long> ans;

int main() {
  int i;
  cin >> n >> l >> t;
  for(i = 0; i < n; ++i) {
    cin >> x >> w;
    if(w == 1) {
      now = x + t;
      ans.push_back(now % l);
      cnter -= now / l;
    }
    else {
      now = t - x;
      if(t >= x) {
        ++cnter;
        if(t % l == x) --cnter;
        cnter += now / l;
      }
      if(now % l == 0)
        now = l;
      else
        now %= l;
      if(t >= x)
        ans.push_back(l - now);
      else
        ans.push_back(-now);
    }
  }
  if(cnter > 0)
    cnter %= n;
  else {
    cnter *= -1;
    cnter = n - cnter % n;
  }
  // cout << cnter << " ";
  sort(ans.begin(), ans.end());
  for(i = 0; i < n; ++i) cout << ans[((n - cnter) + i) % n] << endl;
  return 0;
}
