#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int64 ai, ao, at, aj, al, as, az;
  cin >> ai >> ao >> at >> aj >> al >> as >> az;

  int64 ans = 0;
  ans += ao;

  int odd_count;
  if (ai % 2 == 1) odd_count++;
  if (aj % 2 == 1) odd_count++;
  if (al % 2 == 1) odd_count++;
  if (odd_count == 0 || odd_count == 3) {
    ans += ai + aj + al;
  } else if (odd_count == 1) {
    ans += ai + aj + al - 1;
  } else {
    if (ai == 0 || aj == 0 || al == 0) {
      ans += ai + aj + al - 2;
    } else {
      ans += ai + aj + al - 1;
    }
  }
  cout << ans << endl;
}