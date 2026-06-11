#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const int INFI = 1000000000;
 const ll INFL = (1LL << 60);

 int main() {
   int N; cin >> N;
   string S1, S2; cin >> S1 >> S2;

   int cnt = 0;
   ll ans;
   bool state;

   if (S1.at(0) == S2.at(0)) {
     ans = 3;
     cnt = 1;
     state = true;
   }
   else {
     ans = 6;
     cnt = 2;
     state = false;
   }

   while (cnt < N) {
     if (S1.at(cnt) == S2.at(cnt)) {
       if (state) ans = ans * 2 % MOD;
       cnt++;
       state = true;
     }
     else {
       if (state) ans =  ans * 2 % MOD;
       else ans = ans * 3 % MOD;
       cnt += 2;
       state = false;
     }
   }

   cout << ans << endl;
 }
