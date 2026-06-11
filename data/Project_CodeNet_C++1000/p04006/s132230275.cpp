#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 4e3 + 5;

int st[N][15];
int lg[N];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, x;
  cin >> n >> x;
  vector < int > a (2 * n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
    st[i][0] = st[i + n][0] = a[i];
  }

  for (int j = 1; j < 15; j++) {
    for (int i = 0; i + (1 << j) <= 2 * n; i++) {
      st[i][j] = min (st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 2; i < N; i++) {
    lg[i] = 1 + lg[i / 2];
  }

  ll mi_cst = LLONG_MAX;
  for (int k = 0; k < n; k++) {
    ll cst = (ll)k * x;
    int p = lg[k + 1];
    for (int i = n; i < 2 * n; i++) {
      // mi from i - k to i.
      cst += min (st[i - k][p], st[i - (1 << p) + 1][p]);
    }
    mi_cst = min (mi_cst, cst);
  }

  cout << mi_cst << '\n';
}
