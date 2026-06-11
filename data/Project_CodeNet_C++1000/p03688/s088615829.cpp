#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > a (n + 1);
  int mx = 0, mi = n + 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max (mx, a[i]);
    mi = min (mi, a[i]);
  }

  if (mx - mi > 1) {
    cout << "No\n";
    return 0;
  }

  if(mx == mi) {
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (a[i] != n - 1) ok = false;
    }
    if (ok) {
      cout << "Yes\n";
      return 0;
    }

    ok = true;
    for (int i = 1; i <= n; i++) {
      if (a[i] > (n / 2)) ok = false;
    }

    if (ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  } else {
    int alone = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == mi) alone++;
    }
    int not_alone = n - alone;

    if(mx >= alone + 1 && mx <= alone + (not_alone / 2)) cout << "Yes\n";
    else cout << "No\n";
  }
}
