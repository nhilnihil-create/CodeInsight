#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int W,a,b;
  cin >> W >> a >> b;
  if (a > b) {
    int temp = a;
    a = b;
    b = temp;
  }
  int ans = b - W - a;
  if (ans > 0) cout << ans << endl;
  else cout << 0 << endl;
  return 0;
}
