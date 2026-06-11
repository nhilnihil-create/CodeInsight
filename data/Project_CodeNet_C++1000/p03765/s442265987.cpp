#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 5;

vector < int > prefs(N), preft(N);

int sums (int l, int r) {
  if (l == 0) return prefs[r];
  return prefs[r] - prefs[l - 1];
}

int sumt (int l, int r) {
  if (l == 0) return preft[r];
  return preft[r] - preft[l - 1];
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  string s, t;
  int q;
  cin >> s >> t >> q;

  prefs[0] = s[0] - 'A' + 1;
  for (int i = 1; i < s.length(); i++) {
    prefs[i] = prefs[i - 1] + (s[i] - 'A' + 1);
  }
  preft[0] = t[0] - 'A' + 1;
  for (int i = 1; i < t.length(); i++) {
    preft[i] = preft[i - 1] + (t[i] - 'A' + 1);
  }

  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (sums(a - 1, b - 1) % 3 == sumt(c - 1, d - 1) % 3) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
