#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
   ll N, ans = 1;
   cin >> N;

   map<ll, ll> PF;

   for (ll i = 2; i <= N; i++) {
     ll tmp = i;
     if (tmp == 2 || tmp == 3) {
       PF[tmp]++;
       continue;
     }
     for (ll p = 2; p * p <= tmp; p++) {
         if (tmp % p != 0) continue;
         ll num = 0;
         while (tmp % p == 0) {
            tmp /= p;
            PF[p]++;
         }
     }
     if (tmp != 1) PF[tmp]++;
   }

   for (auto q : PF) {
     ans = ans * (q.second + 1) % MOD;
   }

   cout << ans << endl;
 }
