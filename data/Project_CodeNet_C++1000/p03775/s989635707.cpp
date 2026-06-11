#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;
using Graph = vector<vector<int>>;

int calcDigit(long long num) {
  int digit = 0;
  while (num) {
    num /= 10;
    digit++;
  }
  return digit;
}

int main() {
  long long n;
  cin >> n;

  int res = (1<<29); // 十分大きい値で初期化
  for (long long a = 1; a*a <= n; a++) {
    if (n % a == 0) {
      long long b = n / a;
      int f = max(calcDigit(a), calcDigit(b));
      res = min(res, f);
    }
  }
  cout << res << endl;

  return 0;
}