#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  int p = count(s.begin(), s.end(), 'p');
  cout << s.size() / 2 - p << endl;
  return 0;
}
