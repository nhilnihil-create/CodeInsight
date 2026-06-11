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
    int n, k; cin >> n >> k;
    vector<int> snake;
    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        snake.push_back(tmp);
    }
    sort(snake.rbegin(), snake.rend());
    int ans = 0;
    for(int i = 0; i < k; ++i){
        ans += snake[i];
    }
    cout << ans << endl;
}

int main(void){
    solve();
    return 0;
}
