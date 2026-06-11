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

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

string S;

int main() {
  cin >> S;
  S = "dreamer" + S;
  reverse(S.begin(), S.end());
  int cur = 0;
  while (cur < S.size() - 7) {
    string sub7 = S.substr(cur, 7);
    if (sub7 == "remaerd") {
      cur += 7;
      continue;
    }

    string sub6 = S.substr(cur, 6);
    if (sub6 == "resare") {
      cur += 6;
      continue;
    }

    string sub5 = S.substr(cur, 5);
    if (sub5 == "maerd" || sub5 == "esare") {
      cur += 5;
      continue;
    }

    cout << "NO";
    return 0;
  }

  cout << "YES";
}
