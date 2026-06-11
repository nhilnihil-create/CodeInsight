#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll mod = 1000000007;

ll C[55][55];
void cominit()
{
  for (int i=0; i<=50; i++) {
    for (int j=0; j<=i; j++) {
      if (j==0 || j==i) C[i][j] = 1LL;
      else C[i][j] = (C[i-1][j-1] + C[i-1][j]);
    }
  }
}

int main()
{
  ll n, a, b; cin >> n >> a >> b;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  sort(v.rbegin(),v.rend());
  cominit();

  double sum = 0;
  rep(i, a) sum += v[i];
  double ave = sum / a;

  ll x = 0;
  ll p = 0;
  for (int i=0; i<n; i++) {
    if (v[i] == v[a-1]) {
      x++;
      if (i < a) p++;
    }
  }

  ll ans = 0;
  if (p == a) {
    for (; p<=b; p++) {
      ans += C[x][p];
    }
  } else {
    ans += C[x][p];
  }

  printf("%.6lf\n", ave);
  cout << ans << endl;

  return 0;
}
