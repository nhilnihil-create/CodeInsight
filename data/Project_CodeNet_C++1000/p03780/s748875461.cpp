#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ull << (b))

using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f64 = double;
using vi32 = vector<i32>;
using vu32 = vector<u32>;
using vi64 = vector<i64>;
using vu64 = vector<u64>;
using vf64 = vector<f64>;
using vstr = vector<string>;
using vvi32 = vector<vi32>;
using vvu32 = vector<vu32>;
using vvi64 = vector<vi64>;
using vvu64 = vector<vu64>;
using vvf64 = vector<vf64>;

template<typename T, typename S> bool amax(T &x, S y) { if (x < y) { x = y; return 1; } return 0; }
template<typename T, typename S> bool amin(T &x, S y) { if (y < x) { x = y; return 1; } return 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
  i32 N, K;
  cin >> N >> K;
  vi32 A(N);
  rep(i, N) cin >> A[i];
  vi32 b(N, false);
  sort(all(A), greater<i32>());
  for(int i = 0; i < N; i++) {
    i32 idx = i;
    i64 sum = 0;
    while (idx < N && sum < K) {
      sum += A[idx++];
    }
    if (sum < K) break;
    sum -= A[--idx];
    i32 ok = idx, ng = N;
    while (ng - ok > 1) {
      i32 md = (ok + ng) / 2;
      if (sum + A[md] >= K) {
        ok = md;
      } else {
        ng = md;
      }
    }
    for (int j = i; j < idx; j++) {
      b[j] = true;
    }
    for (int j = idx; j <= ok; j++) {
      b[j] = true;
    }
  }
  int ans = 0;
  rep(i, N) if (!b[i]) ans++;
  cout << ans << endl;
  return 0;
}