#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int cnt = 0;

  if (a == b && b == c) {
    cnt = 1;
  } else if ((a == b && b != c) || (a == c && a != b) || (b == c && b != a)) {
    cnt = 2;
  } else {
    cnt = 3;
  }

  cout << cnt << endl;

  return 0;
}