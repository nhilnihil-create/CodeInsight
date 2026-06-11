#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
   string s;
   cin >> s;
   int n = s.size() - 1;

   ll sum = 0;
   for(int bit = 0; bit < (1<<n); bit++) {
      ll t = s[0] - '0';
      rep(i, n) {
         if ((bit >> i) & 1) {
            sum += t;
            t = s[i+1] - '0';
         } else {
            t *= 10;
            t += s[i+1] - '0';
         }
      }
      sum += t;
   }

   cout << sum << endl;

   return 0;
}