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

string s;

int main() {
  cin >> s;
  int begin = 0;
  int end = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'A') {
      begin = i;
      break;
    }
  }
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == 'Z') {
      end = i;
      break;
    }
  }

  cout << end - begin + 1;
}
