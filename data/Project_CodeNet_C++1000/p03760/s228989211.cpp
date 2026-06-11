#include <bits/stdc++.h>
using namespace std;
int main()
  {string s[2]; cin >> s[0] >> s[1];
  for (int i{}; i < s[0].size() + s[1].size(); ++i) cout << s[i % 2][i / 2];}