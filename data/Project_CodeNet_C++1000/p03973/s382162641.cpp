#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll ans = a[0] - 1;
  int mx = 2;
  for (int i = 1; i < n; i++) {
    if (a[i] == mx) mx++;
    else if (a[i] > mx) {
      ans += (a[i] - 1) / mx;
    }
  }

  cout << ans << '\n';
}
