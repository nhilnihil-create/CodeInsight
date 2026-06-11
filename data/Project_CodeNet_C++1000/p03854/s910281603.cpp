#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  string s;
  cin >> s;

  string tmp = s;

  vector<string> temp = {"dream", "dreamer", "eraser", "erase"};
  sort(temp.begin(), temp.end());
  do {
    s = tmp;
    for (int i = 0; i < temp.size(); i++) {
      auto pos = s.find(temp[i]);
      while (pos != string::npos) {
        s.erase(s.begin() + pos, s.begin() + pos + temp[i].size());
        pos = s.find(temp[i], pos);
      }
    }
    // cout << s << endl;
    if (s.empty()) {
      cout << "YES" << endl;
      return 0;
    }

  } while (next_permutation(temp.begin(), temp.end()));

  cout << "NO" << endl;
}