#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> VI;
int main() {
  int N;
  int MA = 1e5 + 10;
  cin >> N;
  VI A(MA);
  rep(i, N) {
    int a;
    cin >> a;
    A.at(a) += 1;
  }
  int b1 = 1;
  int b2 = 2;

  ll cnt = 0;
  while (b1 < MA && b2 < MA) {
    int minva = min(A.at(b1), A.at(b2));
    if (minva > 1) {
      cnt += (minva - 1) * 2;
      A.at(b1) -= (minva - 1);
      A.at(b2) -= (minva - 1);
    }
    if (A.at(b1) < 2) {
      b1 = max(b1, b2) + 1;
    } else {
      b2 = max(b1, b2) + 1;
    }
  }
  int maxi = 1;
  rep(i, MA) {
    if (A.at(i) > 1) {
      maxi = A.at(i);
      break;
    }
  }
  cnt += (maxi / 2) * 2;

  cout << N - cnt << endl;
  return 0;
}
