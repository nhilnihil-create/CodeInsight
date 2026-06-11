#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  map<char, int> mp;
  int n = s.size();
  rep(i, 0, n) mp[s[i]]++;

  if (mp.size() == 4)
    cout << "Yes" << endl;
  else if (mp.size() == 2) {
    char x[2];
    int i = 0;
    for (auto m : mp) {
      x[i] = m.first;
      i++;
    }
    if ((x[0] == 'N' && x[1] == 'S') || (x[0] == 'E' && x[1] == 'W'))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  } else
    cout << "No" << endl;
}
