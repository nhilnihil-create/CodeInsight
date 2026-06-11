#include <bits/stdc++.h>

using namespace std;

bool StartsWith(string &s, string &t, int offset) {
  int slen = s.size() - offset;
  if (slen < t.size()) {
    return false;
  }

  for (int i = 0; i < t.size(); ++i) {
    if (t[i] != s[offset + i]) {
      return false;
    }
  }

  return true;
}

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  vector<string> vt{"dream", "dreamer", "erase", "eraser"};
  reverse(s.begin(), s.end());
  for (int i = 0; i < vt.size(); ++i) {
    reverse(vt[i].begin(), vt[i].end());
  }

  int cur = 0;
  bool ans = true;
  while (cur < s.size()) {
    int matched_idx = -1;
    for (int i = 0; i < vt.size(); ++i) {
      bool matched = StartsWith(s, vt[i], cur);
      if (matched) {
        matched_idx = i;
        break;
      }
    }

    if (matched_idx == -1) {
      ans = false;
      break;
    }

    cur += vt[matched_idx].size();
  }

  if (ans) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }

  return 0;
}