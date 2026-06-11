#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  replace(S.begin(), S.end(), ',', ' ');
  cout << S << endl;
  return 0;
}