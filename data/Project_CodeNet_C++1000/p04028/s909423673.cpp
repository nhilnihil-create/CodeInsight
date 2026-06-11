#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5005;
const ll mod = (ll)1e9 + 7;

int n, m;
string str;
ll dp[N][N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

int main(){
    cin >> n >> str;
    m = str.length();
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(j >= 1) dp[i][j] += 2 * dp[i-1][j-1];
            if(j == 0) dp[i][j] += dp[i-1][j];
            dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][m] * fp(fp(2, m), mod - 2) % mod << endl;

}
