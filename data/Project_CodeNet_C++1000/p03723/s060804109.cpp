#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int A, B, C; cin >> A >> B >> C;
  int a = A, b = B, c = C;
  int ans=0;
  while (a % 2 != 1 && b % 2 != 1 && c % 2 != 1 ) {
    if (A == B && B == C) {
      ans = -1;
      break;
    }
    A = b / 2 + c / 2;
    B = c / 2 + a / 2;
    C = a / 2 + b / 2;
    a = A, b = B, c = C;
    ans++;
  }
  cout << ans << endl;
  return 0;
}