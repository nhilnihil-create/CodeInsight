#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve(ll A, ll B, ll C) {
  int ans{0};
  if (A%2 || B%2 || C%2) {
    ans = 0;
  } else if (A==B && B==C) {
    ans = -1;
  } else {
    while(A%2==0 && B%2==0 && C%2==0) {
      int newA = (B+C)/2;
      int newB = (A+C)/2;
      C = (A+B)/2;
      A = newA;
      B = newB;
      ++ans;
    }
  }
  cout << ans << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll C;
  cin >> C;
  solve(A, B, C);
  return 0;
}
