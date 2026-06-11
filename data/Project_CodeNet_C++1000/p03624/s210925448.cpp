#include <bits/stdc++.h>
using namespace std;
int main()
  {string S; cin >> S;
  for (auto c{'a'}; c <= 'z'; ++c) if (!~S.find(c)) cout << c << endl, exit(0);
  puts("None");}