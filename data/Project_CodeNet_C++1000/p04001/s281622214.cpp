#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  string s;
  cin >> s;
  int len = s.size();
  ll result = 0;
  result += stoll(s);
  for (int flags = 1; flags < 1 << (len - 1); ++flags) {
    vector<int> pos;
    for (int p = 0; p < len - 1; ++p) {
      if (flags & 1 << p) pos.push_back(p);
    }
    int posLen = pos.size();
    for (int i = 0; i < posLen; ++i) {
      int start = i == 0 ? 0 : pos[i - 1] + 1;
      int length = pos[i] + 1 - start;
      result += stoll(s.substr(start, length));
    }
    result += stoll(s.substr(pos[posLen - 1] + 1, len - pos[posLen - 1]));
  }
  cout << result << endl;
}