#include <iostream>
using namespace std;
using ll = long long;

/*
例えば1から100の間に3で割り切れる数がいくつあるかを考えたとき, 100/3=33.333で33個だと分かる.
1からbの間にあるxで割り切れる数の個数から, 1からaの間にあるxで割り切れる数の個数を引けば,
aからbの間にあるxで割り切れる数の個数が求められる. ただし, aがxで割り切れるならaを個数に含み,
割り切れないなら含まない.
*/

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  cout << (b / x) - (a / x) + !(a % x) << endl;
}