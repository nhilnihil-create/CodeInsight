#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
     int N;
     cin >> N;

     int cnt_odd = 0, cnt_4 = 0;
     rep(i, 0, N) {
       int tmp;
       cin >> tmp;
       if (tmp % 2 == 1) cnt_odd++;
       else if (tmp % 4 == 0) cnt_4++;
     }

     string ans = "Yes";

     if (cnt_odd - cnt_4 > 1) ans = "No";
     else if (cnt_odd - cnt_4 == 1 && cnt_odd + cnt_4 != N) ans = "No";

     cout << ans << endl; 
 }
