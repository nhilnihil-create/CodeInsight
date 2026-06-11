#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string s;
  cin >> s;
  bool N = false;
  bool W = false;
  bool S = false;
  bool E = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'N') {
      N = true;
    }
    if (s[i] == 'W') {
      W = true;
    } 
    if (s[i] == 'S') {
      S = true;
    } 
    if (s[i] == 'E') {
      E = true;
    } 
  }
  bool ans = true;
  if ((!N && S) || (N && !S)) {
    ans = false;
  }
  if ((!W && E) || (W && !E)) {
    ans = false;
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}