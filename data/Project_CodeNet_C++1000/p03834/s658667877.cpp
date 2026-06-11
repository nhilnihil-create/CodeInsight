#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string ans = s.replace(5, 1, " ").replace(13, 1, " ");

  cout << ans << endl;
}