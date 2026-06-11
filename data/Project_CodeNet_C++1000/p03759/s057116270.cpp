#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c; cin >> a >> b >> c;
  string ans;
  if (b - a == c - b) ans = "YES";
  else ans = "NO";
  cout << ans << endl;
}