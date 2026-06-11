#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N, M;
   cin >> N >> M;
   vector<vector<int>> A(N, vector<int>(M));
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         cin >> A[i][j];
         --A[i][j];
      }
   }
   int ans = N;
   vector<bool> ban(M);
   for (int iter = 0; iter < M; ++iter) {
      vector<int> cnt(M);
      for (int i = 0; i < N; ++i) {
         for (int j = 0; j < M; ++j) {
            if (!ban[A[i][j]]) {
               ++cnt[A[i][j]];
               break;
            }
         }
      }
      int z = max_element(cnt.begin(), cnt.end()) - cnt.begin();
      ans = min(ans, cnt[z]);
      ban[z] = true;
   }
   cout << ans << "\n";
   return 0;
}
