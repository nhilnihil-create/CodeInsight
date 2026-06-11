#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   string S;
   cin >> S;
   int N = S.size();
   int ans = N;
   for (char c = 'a'; c <= 'z'; ++c) {
      if (!count(S.begin(), S.end(), c)) continue;
      string T = S;
      int sz = N;
      while (T != string(sz, c)) {
         string newT;
         for (int i = 0; i < sz - 1; ++i) {
            if (T[i] == c || T[i + 1] == c) {
               newT += c;
            } else {
               newT += T[i + (rand() & 1)];
            }
         }
         T = newT;
         --sz;
      }
      ans = min(ans, N - sz);
   }
   cout << ans << "\n";
   return 0;
}
