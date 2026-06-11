#include <bits/stdc++.h>

#define stirng string
#define vvi vector<vector<int>>
#define vi vector<int>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int INF = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  char p[s.size()];
  for (int i = 0; i < s.size(); i++) {
    p[i] = s[s.size() - 1 - i];
    if (p[i] == 'b')
      p[i] = 'd';
    else if (p[i] == 'd')
      p[i] = 'b';
    else if (p[i] == 'q')
      p[i] = 'p';
    else if (p[i] == 'p')
      p[i] = 'q';
    if (p[i] != s[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
