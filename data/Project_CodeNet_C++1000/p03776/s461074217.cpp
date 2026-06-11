#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

void solve();

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

int nCk[51][51];

void solve() {
  int N, A, B;
  cin >> N >> A >> B;

  for (int i = 0; i <= 50; i++) {
    nCk[0][i] = 1;
    nCk[i][i] = 1;
  }

  for (int k = 2; k <= 50; k++) {
    for (int n = 1; n < k; n++) {
      nCk[n][k] = nCk[n-1][k-1] + nCk[n][k-1];
    }
  }

  map<int, int> cnt;

  vector<int> V(N);
  for (int &v:V) {
    cin >> v;
    cnt[v]++;
  }

  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());

  int sum = 0;
  map<int, int> cnt_sum;

  for (int i = 0; i < A; i++) {
    sum += V[i];
    cnt_sum[V[i]]++;
  }

  int a = V[A-1];

  double maxi = sum/(double)A;
  int ans = nCk[cnt_sum[a]][cnt[a]];

  if (sum%A == 0 && sum/A == a) {
    for (int i = 1; i <= min(B-A, cnt[a]-cnt_sum[a]); i++) {
      ans += nCk[cnt_sum[a]+i][cnt[a]];
    }
  }

  printf("%.6lf\n%lld\n", maxi, ans);
}
