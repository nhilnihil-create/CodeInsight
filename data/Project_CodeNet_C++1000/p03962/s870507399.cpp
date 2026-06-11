#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  set<int> x;
  x.insert(a);
  x.insert(b);
  x.insert(c);
  cout << x.size() << endl;
  return 0;
}
