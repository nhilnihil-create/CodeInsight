#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    ans += (r - l + 1);
  }
  cout << ans << endl;

  return 0;
}
