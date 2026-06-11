#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
     ll N;
     cin >> N;
     vector<ll> Acnt(N);

     rep(i, 0, N) {
       ll tmp;
       cin >> tmp;
       Acnt.at(tmp)++;
     }

     if (N % 2 == 1) {
       bool ok = true;
       if (Acnt.at(0) == 0) ok = false;
       for (int i = 1; i <= N - 1; i++) {
         if (i % 2 == 1 && Acnt.at(i) != 0) ok = false;
         if (i % 2 == 0 && Acnt.at(i) != 2) ok = false;
       }
       if (ok) {
         int ans = 1;
         rep(i, 0, (N - 1) / 2) ans = ans * 2 % MOD;
         cout << ans << endl;
       }
       else cout << 0 << endl;
     }

     else {
       bool ok = true;
       for (int i = 1; i <= N - 1; i++) {
         if (i % 2 == 1 && Acnt.at(i) != 2) ok = false;
         if (i % 2 == 0 && Acnt.at(i) != 0) ok = false;
       }
       if (ok) {
         int ans = 1;
         rep(i, 0, N / 2) ans = ans * 2 % MOD;
         cout << ans << endl;
       }
       else cout << 0 << endl;
     }
 }
