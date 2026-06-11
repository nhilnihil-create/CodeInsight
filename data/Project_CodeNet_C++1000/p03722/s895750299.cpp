#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MAXC 1000000000LL

bool chmin(ll& a, ll b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n, m; cin >> n >> m;
  vector<int> a(m), b(m);
  vector<ll> c(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--; c[i] *= -1;
  }

  vector<ll> dist(n, MAXC * (n-1));
  dist[0] = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < m; j++) {
      chmin(dist[b[j]], dist[a[j]] + c[j]);
    }
  }

  vector<bool> negative(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (chmin(dist[b[j]], dist[a[j]] + c[j]) || negative[a[j]]) {
        negative[b[j]] = true;
      }
    }
  }

  if (negative[n-1])
    cout << "inf" << endl;
  else
    cout << -dist[n-1] << endl;
}