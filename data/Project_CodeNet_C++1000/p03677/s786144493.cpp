#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
bool Can_Match[10];
int main() {
  int n,m;
  cin >> n >> m;
  int a[n];
  int star[m];
  int end[m];
  int fall[m];
  ll diff[m];
  for (int i = 0; i < m; i++) {
    star[i] = 0;
    end[i] = 0;
    fall[i] = 0;
    diff[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  for (int i = 1; i < n; i++) {
    if (a[i-1] < a[i]) {
      if (a[i] - a[i-1] >= 2) {
        star[a[i-1]+2]++;
        end[a[i]]++;
      }
    } else {
      if (a[i] + m - a[i-1] >= 2) {
        if (a[i-1]+2 < m) {
          star[a[i-1]+2]++;
          end[m-1]++;
        }
        star[0]++;
        end[a[i]]++;
      }
    }
  }
  diff[0] = 0;
  for (int i = 1; i < n; i++) {
    if (a[i-1] < a[i]) {
      if (a[i] - a[i-1] >= 2) {
        fall[(a[i]+1)%m] += a[i] - a[i-1] - 1;
      }
    } else {
      if (a[i] - a[i-1] + m >= 2) {
        fall[(a[i]+1)%m] += a[i] - a[i-1] + m - 1;
      }
    }
  }
  int Kukan = 0;
  Kukan += star[0];
  Kukan -= end[0];
  for (int i = 1; i < m; i++) {
    Kukan += star[i];
    diff[i] = diff[i-1] + Kukan;
    diff[i] -= fall[i];
    Kukan -= end[i];
  }
  ll max_diff = 0;
  for (int i = 0; i < m; i++) {
    max_diff = max(max_diff,diff[i]);
  }
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i-1] < a[i]) {
      ans += a[i] - a[i-1];
    } else {
      ans += 1 + a[i];
    }
  }
  cout << ans - max_diff << endl;
  return 0;
}