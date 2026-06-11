#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, a, b;
   cin >> n >> a >> b;
   string s;
   cin >> s;
   int aq = 0;
   int bq = 0;
   vector<string> ans(n);
   for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
         if (aq + bq < a + b) {
            ans[i] = "Yes";
            aq++;
         }
         else ans[i] = "No";
      }
      else if (s[i] == 'b') {
         if (aq + bq < a + b && bq < b) {
            ans[i] = "Yes";
            bq++;
         }
         else ans[i] = "No";
      }
      else ans[i] = "No";
   }
   for (int i = 0; i < n; i++) {
      cout << ans[i] << '\n';
   }
   return 0;
}