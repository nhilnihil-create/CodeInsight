#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int n;
  cin >> n;
  deque<ll> A{};
  REP(i, n) {
    ll a;
    cin >> a;
    A.push_back(a);
  }
  deque<ll> B{};
  bool tenti = false;
  REP(i, n) {
    if (tenti) {
      B.push_front(A[i]);
    } else {
      B.push_back(A[i]);
    }
    tenti = !tenti;
  }
  if (tenti) reverse(B.begin(), B.end());
  REP(i, n - 1) { cout << B[i] << " "; }
  cout << B[n - 1] << endl;
}