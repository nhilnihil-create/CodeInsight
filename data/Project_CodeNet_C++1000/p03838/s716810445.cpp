#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int64_t x, y;
  cin >> x >> y;
  int64_t count = 10000000000;
  int64_t count1 = (x <= y) ? y-x : -1;
  int64_t count2 = (-x <= y) ? y+x+1 : -1;
  int64_t count3 = (x <= -y) ? -y-x+1 : -1;
  int64_t count4 = (-x <= -y) ? -y+x+2 : -1;
  count = 0 < count1 ? count1 : count;
  count = 0 < count2 ? min(count, count2) : count;
  count = 0 < count3 ? min(count, count3) : count;
  count = 0 < count4 ? min(count, count4) : count;
  cout << count << endl;
  return 0;
}
