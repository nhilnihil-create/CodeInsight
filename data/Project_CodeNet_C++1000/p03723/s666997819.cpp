#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int A, B, C;
  cin >> A >> B >> C;
  if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
    cout << 0 << endl;
    return 0;
  } else if (A == B && A == C) {
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
    ans++;
    int a = A,b = B, c = C;
    A = b / 2 + c / 2;
    B = a / 2 + c / 2;
    C = a / 2 + b / 2;
    //cout << A << " " << B << " " << C << endl;
  }
  cout << ans << endl;
}