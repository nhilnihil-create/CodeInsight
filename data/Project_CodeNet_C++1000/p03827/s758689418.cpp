#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, x{}, m{}; string S; cin >> N >> S;
  for (auto c : S) {x += c == 'I' ? 1 : -1; m = max(m, x);}
  cout << m << endl;}