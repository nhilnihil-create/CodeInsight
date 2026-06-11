#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  string s = to_string(n);
  bool ok = true;
  for (int i = 0; i < s.length() / 2; i++) 
    if (s[i] != s[s.length() - i - 1])
      ok = false;
  cout << (ok ? "Yes\n" : "No\n"); 
  return 0;
}