#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int ans = 0;
  rep(i, n) {
    // rep 一回につき、一数列
    while (i + 1 < n && a[i] == a[i + 1]) i++;

    if (i + 1 < n && a[i] < a[i + 1]) {
      while (i + 1 < n && a[i] <= a[i + 1]) i++;
    } else if (i + 1 < n && a[i] > a[i + 1]) {
      while (i + 1 < n && a[i] >= a[i + 1]) i++;
    }
    
    ans++;
  }
  cout << ans << endl;
  return 0;
}