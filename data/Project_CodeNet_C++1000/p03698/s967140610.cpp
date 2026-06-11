#include <bits/stdc++.h>
using namespace std;
int C[26];
int main()
  {string S; cin >> S; for (auto c : S) ++C[c - 'a'];
  for (int c : C) if (c > 1) puts("no"), exit(0);
  puts("yes");}