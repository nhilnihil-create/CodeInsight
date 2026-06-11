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
const long long MINF = LLONG_MIN;

// -------------------------------------------------------

ll N;
ll a[301010];
ll csum[101010], rcsum[101010];

int main() {
  cin >> N;
  repe(i, 1, 3 * N) { cin >> a[i]; }

  priority_queue<int, vector<int>, greater<int>> que;
  ll sum = 0;
  repe(i, 1, N) {
    que.push(a[i]);
    sum += a[i];
  }

  csum[0] = sum;
  repe(i, 1, N) {
    ll mi = que.top();
    ll na = a[N + i];
    if (na > mi) {
      csum[i] = csum[i - 1] + na - mi;
      que.pop();
      que.push(na);
    } else {
      csum[i] = csum[i - 1];
    }
  }

  priority_queue<int> rque;
  ll rsum = 0;
  rep(i, 0, N) {
    rque.push(a[3 * N - i]);
    rsum += a[3 * N - i];
  }

  rcsum[N] = rsum;
  repe(i, 1, N) {
    ll ma = rque.top();
    ll na = a[2 * N + 1 - i];
    if (na < ma) {
      rcsum[N - i] = rcsum[N - i + 1] - ma + na;
      rque.pop();
      rque.push(na);
    } else {
      rcsum[N - i] = rcsum[N - i + 1];
    }
  }

  ll ans = MINF;
  repe(i, 0, N) { chmax(ans, csum[i] - rcsum[i]); }
  cout << ans;
}
