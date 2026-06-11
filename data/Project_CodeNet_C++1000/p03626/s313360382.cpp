#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}
const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i>n || i < 0) return 0; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){
      ans *=(n+1-j);
      ans /= j;
      ans %= MOD;} }return ans;}

template<typename T> T gcd(T a, T b){if(b == 0) return a;else return gcd(b, a%b);}
template<typename T> T lcm(T a, T b){if(b > a) swap(a, b); T g = gcd(a, b);return a / g * b;
}


void solve() {
    int n; cin >> n;
    string up, low; cin >> up >> low;
    int x = 0;
    ll ans = 1;
    int pre = -1;
    while(x < n){
        // printf("x: %d, ans: %lld\n", x, ans);
        if(x == 0){
            if(up[x] == low[x]){
                ans *= 3;
                ans %= MOD;
                x++;
                pre = 1;
            } else {
                ans *= 3 * 2;
                ans %= MOD;
                x += 2;
                pre = 2;
            }
        } else {
            if(up[x] == low[x] && pre == 2){
                ans *= 1;
                ans %= MOD;
                x++;
                pre = 1;
            } else if(up[x] == low[x] && pre == 1){
                ans *= 2;
                ans %= MOD;
                x++;
                pre = 1;
            } else if(pre == 1){
                ans *= 2;
                ans %= MOD;
                x += 2;
                pre = 2;
            } else {
                ans *= 3;
                ans %= MOD;
                x += 2;
                pre = 2;
            }
        }
    }
    cout << ans << endl;
}

int main(void){
  solve();
  return 0; 
}
