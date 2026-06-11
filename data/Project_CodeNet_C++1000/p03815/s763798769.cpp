#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
     ll x, ans = 0;
     cin >> x;

     ans += x / 11 * 2;
     x %= 11;
     if (x > 0 && x <= 6) ans++;
     else if (x >= 7) ans += 2;

     cout << ans << endl;
 }
