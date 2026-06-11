#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
// const long long INF = 1LL << 60;
const int INF = 1010101010;
using Graph = vector<vector<int>>;

int main() {
  string s2;
  cin >> s2;
  int mi = INF;
  bool ok = true;
  for (int i = 0; i < s2.length(); i++) {
    if (s2[i] != s2[0]) {
      ok = false;
    }
  }
  if (ok) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i < 26; i++) {
    string s = s2;
    char c = (char)(i + 'a');
    int cnt = 0;
    while (true) {
      bool ok = true;
      string t = "";
      for (int j = 0; j < s.length() - 1; j++) {
        if (s[j + 1] == c || s[j] == c) {
          t.push_back(c);
        } else {
          t.push_back(s[j]);
          ok = false;
        }
      }
      s = t;
      cnt++;
      if (ok) break;
      if (s.length() - 1 == 0) break;
    }
    mi = min(cnt, mi);
  }

  cout << mi << endl;
}