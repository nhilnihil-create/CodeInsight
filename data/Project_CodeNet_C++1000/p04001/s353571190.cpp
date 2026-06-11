#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0;i < (n);i++)
using namespace std;
typedef long long ll;

int f() {

}
int main() {
   char n[10];
   cin >> n;
   ll ans = 0;
   for(int bit = 0;bit < (1 << strlen(n)-1);bit++) {
      ll a = n[0] - '0';
      rep(i, strlen(n)-1) {
         ll j = n[i] - '0';
         if(bit & (1<<i)) {
            ans += a;
            a = n[i+1]- '0';
         }else {
            a = a *10 + (n[i+1]-'0');
         }
         
      }
      ans += a;
   }
   cout << ans << endl;
}