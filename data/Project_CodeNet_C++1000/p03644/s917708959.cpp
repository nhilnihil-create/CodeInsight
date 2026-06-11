#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}
const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i>n || i < 0) return 0; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){
      ans *=(n+1-j);
      ans /= j;
      ans %= MOD;} }return ans;}

void solve(){
   int n; cin >> n;
   int ans = 0;
   int kijun = -1;
   for(int i = 1; i <= n; ++i){
       int tmp = i;
       int cnt = 0;
       while(tmp){
           if(tmp%2 == 0){
            tmp/=2;
            cnt++;
           } else {
               break;
           }
       }
        if(cnt > kijun) {
            ans = i;
            kijun = cnt;
        }
   }
   cout << ans << endl;
}

int main(void){
    solve();
    return 0;
}
