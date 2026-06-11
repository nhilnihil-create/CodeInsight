#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   string S, T;
   cin >> S >> T;
   int N = S.size();
   int M = T.size();
   vector<int> prefS(N + 1);
   vector<int> prefT(M + 1);
   for (int i = 0; i < N; ++i) {
      prefS[i + 1] = prefS[i] + (S[i] == 'A' ? 1 : 2);
   }
   for (int i = 0; i < M; ++i) {
      prefT[i + 1] = prefT[i] + (T[i] == 'A' ? 1 : 2);
   }
   int Q;
   cin >> Q;
   while (Q--) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      --a, --b, --c, --d;
      int vs = (prefS[b + 1] - prefS[a]) % 3;
      int vt = (prefT[d + 1] - prefT[c]) % 3;
      if (vs == vt) {
         cout << "YES\n";
      } else {
         cout << "NO\n";
      }
   }
}
