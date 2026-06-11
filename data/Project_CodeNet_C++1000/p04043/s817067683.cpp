#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if ((a == 5 && b == 5 && c == 7) || (a == 5 && b == 7 && c == 5) || (a == 7 && b == 5 && c == 5)) {
      cout << "YES" << endl;
      return 0;
  }
  cout << "NO" << endl;

  return 0;
}