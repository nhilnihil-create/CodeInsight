#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s; 
  cin >> s;
  int n = s.size();
  cout << s[0] << n-2 << s[n-1] << endl;

  return 0;
}

