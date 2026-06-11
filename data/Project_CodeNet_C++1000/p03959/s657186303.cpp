#include <bits/stdc++.h>
using namespace std;

int main() {
  int MOD = 1000000007;
  int N; cin >> N;
  vector<long long> T(N), A(N);
  for (int i = 0; i < N; i++) cin >> T.at(i);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  // 最高が更新された地点の記録
  vector<bool> TB(N), AB(N);
  int tmp_t = -1, tmp_a = -1;
  for (int i = 0; i < N; i++) {
    if (T.at(i) != tmp_t) TB.at(i) = true;
    tmp_t = T.at(i);
    if (A.at(N-1-i) != tmp_a) AB.at(N-1-i) = true;
    tmp_a = A.at(N-1-i);
  }
  // 整合性のチェック
  for (int i = 0; i < N; i++) {
    if (TB.at(i) && AB.at(i)) {
      if (T.at(i) != A.at(i)) { cout << 0 << endl; return 0; }
    }
    else if (TB.at(i)) {
      if (T.at(i) > A.at(i)) { cout << 0 << endl; return 0; }
    }
    else if (AB.at(i)) {
      if (A.at(i) > T.at(i)) { cout << 0 << endl; return 0; }
    }
  }
  long long ans = 1;
  for (int i = 0; i < N; i++) {
    if (TB.at(i) || AB.at(i)) continue;
    else ans = ans * min(T.at(i), A.at(i)) % MOD;
  }
  cout << ans << endl;
}