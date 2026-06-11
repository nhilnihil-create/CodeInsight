#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll h, w, n;
  cin >> h >> w >> n;

  vll a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  ll y = 0, x = 0;
  vector<vll> grid(h, vll(w));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < a[i]; j++) {
      grid[y][x] = i + 1;
      x++;
      if (x == w) {
        x = 0;
        y++;
      }
    }
  }

  for (ll i = 1; i < h; i += 2) reverse(all(grid[i]));

  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w - 1; j++) cout << grid[i][j] << " ";
    cout << grid[i][w - 1] << endl;
  }
}