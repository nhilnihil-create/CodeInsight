#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt2 = 0, cnt4 = 0;
  rep(i,n) {
    int a;
    cin >> a;
    if (a % 4 == 0) ++cnt4;
    else if (a % 2 == 0) ++cnt2;
  }

  if (n - cnt2 <= cnt4 * 2) cout << "Yes" << endl;
  else if (cnt4 >= n / 2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}