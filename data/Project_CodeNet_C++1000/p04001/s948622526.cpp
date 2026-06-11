#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int ctoi(char c) {
  switch (c) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    default:
      return 0;
  }
}

int main() {
  string S;
  cin >> S;

  int length = S.size();
  int power = length - 1;
  ll sum = 0;

  for (int i = 0; i < (1 << power); i++) {
    bitset<10> b_plus(i);
    b_plus.set(power, 1);  // add finally
    ll tmp = 0;
    rep(j, length) {
      tmp = (tmp * 10) + ctoi(S.at(j));
      if (b_plus.test(j)) {
        sum += tmp;
        tmp = 0;
      }
    }
  }

  cout << sum << endl;
}
