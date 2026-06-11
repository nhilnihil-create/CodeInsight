#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

typedef pair<int, int> p_ii;

int main() {
  int N; cin >> N;
  p_ii A[N];
  rep(i,N) { int tmp; cin >> tmp; A[i] = make_pair(i, tmp); }
  sort(A, A+N, [](const p_ii& x, const p_ii& y){return x.second < y.second;});
  // rep(i,N) cout << A[i].first << ":" << A[i].second << endl;
  int result = 0;
  rep(i,(N+1)/2) if (A[i*2].first%2==1) result++;
  cout << result << endl;
  return 0;
}