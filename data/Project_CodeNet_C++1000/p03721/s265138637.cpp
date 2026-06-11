#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  ll N, K;
  cin >> N >> K;
  vector<P> A(N);
  REP(i, N) cin >> A[i].first >> A[i].second;
  sort(A.begin(), A.end());
  ll i = 0;
  while(0<K){
    K -= A[i].second;
    if (K <= 0) break;
    i++;
  }
  cout << A[i].first << endl;
}