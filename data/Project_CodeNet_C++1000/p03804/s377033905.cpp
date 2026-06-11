#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;

// -------------------------------------------------------

int N, M;
string A[100], B[100];

int main() {
  cin >> N >> M;
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, M) { cin >> B[i]; }
  rep(i, 0, N) {
    rep(j, 0, N) {
      bool ok = true;
      rep(k, 0, M) {
        rep(l, 0, M) {
          if (B[k][l] != A[i + k][j + l]) {
            ok = false;
            break;
          }
        }
        if (!ok) break;
      }
      if (ok) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
