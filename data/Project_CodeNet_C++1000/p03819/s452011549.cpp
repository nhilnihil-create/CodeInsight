#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  float m_ = sqrt(M);
  int m = floor(m_);
  if (m*m > M) {
    m -= 1;
  }
  
  vector<int> ans(M+1), imos(M+2);
  int l, r, ll, rr, l_prev;
  int i;
  rep(j, N) {
    cin >> l >> r;
    rep (i_, m) {
        i = i_ + 1;
        ll = (l-1) / i + 1;
        rr = r / i;
        if (rr >= ll) {
          ans[i] += 1;
        }
    }
    imos[l] += 1;
    imos[r+1] -= 1;
    l_prev = l;
    rep(i_, m-1) {
      i = i_ + 2;
      ll = (l-1) / i + 1;
      rr = r / i;
      if (rr >= ll) {
        if (rr < l_prev) {
          imos[ll] += 1;
          imos[rr+1] -= 1;
        }
        else {
          imos[ll] += 1;
          imos[l_prev] -= 1;
        }
        l_prev = ll;
      }
    }
  }

  vector<int> ans2(M+1);
  rep(i_, M+1) {
    i = i_ + 1;
    ans2[i] = ans2[i-1] + imos[i];
  }
  rep(i_, m) {
    i = i_ + 1;
    cout << ans[i] << "\n";
  }
  rep(i_, M-m) {
    i = i_ + m + 1;
    cout << ans2[i] << "\n";
  }
}
