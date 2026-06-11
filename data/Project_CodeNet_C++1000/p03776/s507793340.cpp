#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end(), greater<ll>());

  ll sum = v[0], p = v[0];
  int c = 1;
  for (int i = 1; i < a; i++) {
    sum += v[i];
    if (v[i] == p) c++;
    else {
      p = v[i];
      c = 1;
    }
  }
  double average = (double)(sum) / a;


  int d = 0;
  for (int i = a; i < n; i++) {
    if (v[i] == p) d++;
    else break;
  }

  ll comb[51][51];
  for (int i = 0; i < 51; i++) {
    comb[i][0] = 1;
    for (int j = 1; j < i; j++) {
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    }
    comb[i][i] = 1;
  }

  ll ans = 0;
  if (c == a) {
    for (int i = a; i <= min(c+d, b); i++) {
      ans += comb[c+d][i];
    }
  }
  else ans = comb[c+d][c];

  cout << fixed << setprecision(10) << average << endl;
  cout << ans << endl;
}