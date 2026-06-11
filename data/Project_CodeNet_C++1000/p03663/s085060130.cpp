#include <bits/stdc++.h>

using namespace std;

const int ANS = 91654010;
const string SANS = "91654010";

string toString(const long long& x) {
  long long temp = x;
  string ret = "";
  while (temp) {
    ret = (char)('0' + temp % 10) + ret;
    temp /= 10;
  }
  return ret;
}

void check(const long long& x, char& ret) {
  string s = toString(x);
  cout << x << " " << s << endl;
  if (x <= ANS && s <= SANS)
    ret = 'Y';
  else if (x > ANS && s > SANS)
    ret = 'Y';
  else
    ret = 'N';
}

bool checkTenPow() {
  char ans;
  cout << "? " << (int)1e9 << endl;
//  check((int)1e9, ans);
  cin >> ans;
  if (ans == 'N')
    return false;
  long long x = 2;
  while (true) {
    cout << "? " << x << endl;
//    check(x, ans);
    cin >> ans;
    if (ans == 'Y') {
      cout << "! " << x / 2 << endl;
      break;
    }
    x *= 10;
  }
  return true;
}

long long getDig() {
  char ans;
  long long ret = 10;
  while (true) {
    cout << "? " << ret << endl;
//    check(ret, ans);
    cin >> ans;
    if (ans == 'N')
      break;
    ret *= 10;
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  if (checkTenPow())
    return 0;
  long long dig = getDig();
  long long l = dig / 10, r = dig - 1;
  char ans;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    cout << "? " << mid << 0 << endl;
//    check(10 * mid, ans);
    cin >> ans;
    if (ans == 'Y')
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << "! " << r + 1 << endl;
  return 0;
}