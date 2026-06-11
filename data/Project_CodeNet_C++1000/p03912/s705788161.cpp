#include <bits/stdc++.h>
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,n,m) for (int i=n; i<(int)(m); ++i)
#define ALL(x) x.begin(), x.end()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define in(i, n) (0 <= (i) && (i) < (n))
#define on(bit, i) (((bit >> i) & 1) == 1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
const int INF = 1e9+7;

int N, M;
map<int, int> mp;

int main(void) {
  cin >> N >> M;
  REP(i, N) {
    int t; cin >> t;
    mp[t]++;
  }
  vector<int> pcnt(M + 1), cnt(M + 1);
  for (auto p : mp) {
    cnt[p.first % M] += p.second;
    pcnt[p.first % M] += p.second / 2;
  }
  int res = 0;
  for (int i = 0; i < M; i++) {
    int j = (M - i + M) % M;
    if (i > j) continue;
    if (i == j) {
      res += cnt[i] / 2;
      //cout << i << " " << cnt[i] / 2 << endl;
    }
    else {
      if (cnt[i] < cnt[j]) {
	int rest = cnt[j] - cnt[i];
	res += cnt[i] + min(pcnt[j], rest / 2);
	//cout << i << " " << cnt[i] + min(pcnt[j], rest / 2) << endl;
      } else {
	int rest = cnt[i] - cnt[j];
	res += cnt[j] + min(pcnt[i], rest / 2);
	//cout << i << " " << cnt[j] + min(pcnt[i], rest / 2) << endl;
      }
    };
  }
  cout << res << endl;
  return 0;
}
