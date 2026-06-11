#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  ll N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  REP(m, N) {
    ll mn = A + m * C - (N - 1 - m) * D;
    ll mx = A + m * D - (N - 1 - m) * C;
    if (mn <= B && B <= mx) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}