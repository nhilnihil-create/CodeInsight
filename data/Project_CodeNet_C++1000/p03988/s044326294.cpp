#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > a (n), cnt (n);
  for (auto &i : a) cin >> i, cnt[i]++;

  int mx = 1;
  for (int i = 0; i < n; i++) {
    if (cnt[i] > 0) mx = i;
  }

  bool ok = true;
  for (int i = 0; i < (mx + 1) / 2; i++) ok &= (cnt[i] == 0);
  for (int i = ((mx + 1) / 2) + 1; i <= mx; i++) ok &= (cnt[i] > 1);
  if (mx & 1) {
    ok &= (cnt[(mx + 1) / 2] == 2);
  } else {
    ok &= (cnt[(mx + 1) / 2] == 1);
  }

  cout << (ok ? "Possible" : "Impossible") << '\n';
}
