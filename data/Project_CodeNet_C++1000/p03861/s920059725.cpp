#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  long long a, b, x, h;
  cin >> a >> b >> x;
  if (a == 0) {
    cout << b / x + 1 << endl;
  } else {
    cout << b / x - (a - 1) / x << endl;
  }
}
