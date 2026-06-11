#include <bits/stdc++.h>
using namespace std;
int main()
  {int H, W; cin >> H >> W;
  string t(W + 2, '#'), s;
  puts(t.c_str());
  while (H--) {cin >> s; printf("#%s#\n", s.c_str());}
  cout << t;}