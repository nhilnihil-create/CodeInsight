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

int N;
map<ll, ll> mp;
vector<ll> canuse;

int main() {
  cin >> N;
  rep(i, 0, N) {
    ll a;
    cin >> a;
    ++mp[a];
  }

  for (auto e : mp) {
    if (e.second >= 4) {
      canuse.push_back(e.first);
      canuse.push_back(e.first);
    } else if (e.second >= 2) {
      canuse.push_back(e.first);
    }
  }

  sort(canuse.begin(), canuse.end(), greater<ll>());

  if (canuse.size() < 2) {
    cout << 0;
  } else {
    cout << canuse[0] * canuse[1];
  }
}
