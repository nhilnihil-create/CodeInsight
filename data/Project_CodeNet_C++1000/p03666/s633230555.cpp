#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N;
  cin >> N;
  ll A,B,C,D;
  cin >> A >> B >> C >> D;
  ll st = (N - 1) * D;
  if (A+st < B || A-st > B) {
    cout << "NO" << endl;
    return 0;
  }
  ll d = D-C;
  ll blank = (2*D) - (N*d) - 1;
  if (blank <= 0) {
    cout << "YES" << endl;
    return 0;
  }
  ll left = A + st - ((N-1) * d);
  ll right = A + st;
  left %= 2*D - d;
  right %= 2*D - d;
  ll per = B % (2*D - d);
  if (left > right) {
    right += 2*D - d;
  }
  ll per2 = per + 2*D - d;
  if (left <= per && per <= right) {
    cout << "YES" << endl;
    return 0;
  } else if (left <= per2 && per2 <= right) {
    cout << "YES" << endl;
    return 0;
  } else {
    cout << "NO" << endl;
    return 0;
  }
  return 0;
}