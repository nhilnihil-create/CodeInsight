#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if (a-b >= 0) cout << "delicious" << endl;
  if (a-b+x < 0) cout << "dangerous" << endl;
  else if (a-b < 0) cout << "safe" << endl;
}