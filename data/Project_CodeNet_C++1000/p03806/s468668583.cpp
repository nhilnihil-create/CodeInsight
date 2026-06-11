#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, MA, MB;
  cin >> N >> MA >> MB;
  vector<int> a(N), b(N), c(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  int ret = 987654321;
  map<pair<int, int>, int> comb;
  comb[make_pair(0, 0)] = 0;
  if (N >= 21) {
    for (int i = 0; i < (1 << (N - 20)); i++) {
      int sa = 0, sb = 0, sc = 0;
      for (int j = 0; j < (N - 20); j++) {
        if (i & (1 << j)) {
          sa += a[20 + j];
          sb += b[20 + j];
          sc += c[20 + j];
        }
      }
      if (comb.count(make_pair(sa, sb)) == 0 ||
          (comb.count(make_pair(sa, sb)) > 0 && comb[make_pair(sa, sb)] > sc)) {
        comb[make_pair(sa, sb)] = sc;
      }
    }
  }

  for (int i = 0; i < (1 << min(N, 20)); i++) {
    int sa = 0, sb = 0, sc = 0;
    for (int j = 0; j < min(N, 20); j++) {
      if (i & (1 << j)) {
        sa += a[j];
        sb += b[j];
        sc += c[j];
      }
    }
    if (sa * MB == sb * MA && (sa + sb > 0)) {
      ret = min(ret, sc);
    } else {
      for (int k = 1; k <= 40; k++) {
        int ta = k * MA - sa, tb = k * MB - sb;
        if (ta >= 0 && tb >= 0 && comb.count(make_pair(ta, tb)) > 0) {
          ret = min(ret, sc + comb[make_pair(ta, tb)]);
        }
      }
    }
  }

  if (ret == 987654321) {
    cout << -1 << endl;
  } else {
    cout << ret << endl;
  }
}