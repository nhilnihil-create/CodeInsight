#include <iostream>

using namespace std;

int main() {
  int x, y, ans{1<<30};
  cin >> x >> y;
  if (x <= y) ans = min(ans, y-x);
  if (-x <= y) ans = min(ans, x+y+1);
  if (x <= -y) ans = min(ans, -x-y+1);
  if (-x <= -y) ans = min(ans, x-y+2);
  cout << ans << endl;
}
