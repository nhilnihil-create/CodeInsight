#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5;
ll x[N], nx[N];
int w[N];

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  ll n, l, t; cin >> n >> l >> t;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> w[i];
    if(w[0] == 2) x[i] = l - 1 - x[i];
    if(w[0] == w[i]) nx[i] = (x[i] + t) % l;
    else nx[i] = ((x[i] - t) % l + l) % l;
  }

  int g1 = 0;
  int g2 = (x[0] + 2 * t) / l;
  int p1 = x[0];
  int p2 = (x[0] + 2 * t) % l;
  ll ch = 0;
  for(int i = 1; i < n; i++) {
    if(w[0] == w[i]) continue;
    int p = x[i];
    if(g1 == g2) {
      if(p1 <= p && p <= p2) ch++;
    } else {
      if(p1 <= p) ch++;
      if(p <= p2) ch++;
      ch += g2 - g1 + 1 - 2;
    }
  }
  int fi;
  if(w[0] == 2) fi = (n - ch) % n;
  else fi = ch % n;
  ll fx = nx[0];
  if(w[0] == 2) {
    for(int i = 0; i < n; i++) nx[i] = l - 1 - nx[i];
    fx = l - 1 - fx;
  }
  sort(nx, nx + n);

  int ti;
  if(w[0] == 2) {
    ti = lower_bound(nx, nx + n, fx) - nx;
  } else {
    ti = upper_bound(nx, nx + n, fx) - nx - 1;
  }
  ti = (n + ti - fi) % n;
  for(int i = 0; i < n; i++) {
    cout << nx[ti] << endl;
    ++ti%=n;
  }
}

