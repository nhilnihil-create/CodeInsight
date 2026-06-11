// d = B - A
// C <= x <= D, -D <= x <= -Cのxを(N-1)個足してdをつくれるか
 
// 正数をm使うとすると
// mC + (N-1-m)(-D) <= B - A <= mD + (N-1-m)(-C) が必要
// この区間の整数を全て取れるので十分
 
#include <iostream>
using ll = long long;
using namespace std;
 
int main() {
  ll N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  ll d = B - A;
  for (int m = 0; m <= N-1; m++) {
    ll l = m * C + (N-1-m) * (-D);
    ll r = m * D + (N-1-m) * (-C);
    if (l <= d && d <= r) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}