#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> cnt(4);
  rep(i, n) {
    if (s[i] == 'N') cnt[0]++;
    if (s[i] == 'S') cnt[1]++;
    if (s[i] == 'E') cnt[2]++;
    if (s[i] == 'W') cnt[3]++;
  }

  bool ok = false, ok1 = false;
  if ((cnt[0] > 0 && cnt[1] > 0) || (cnt[0] == 0 && cnt[1] == 0)) ok = true;
  if ((cnt[2] > 0 && cnt[3] > 0) || (cnt[2] == 0 && cnt[3] == 0)) ok1 = true;

  if (ok && ok1) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
