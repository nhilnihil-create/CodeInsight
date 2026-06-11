#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }
  int ans = 0;
  vector<int> flag(N);
  for (int i = 0; i < N - 1; i++) {
    if (!flag[i] && !flag[i + 1] && A[i] == i && A[i + 1] == i + 1) {
      ans++;
      flag[i] = flag[i + 1] = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    if (!flag[i] && A[i] == i) {
      ans++;
    }
  }

  cout << ans << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(16);
  solve();
  return 0;
}