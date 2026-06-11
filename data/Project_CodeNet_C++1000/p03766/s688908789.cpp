#include <iostream>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;

int add(int& x, int y){
    if((x += y) >= mod) x -= mod;
    return x;
}

int mul(int x, int y){
    return (int)((ll)x * y % mod);
}

int dp[1000005];

int main(){
    int n;
    cin >> n;
    dp[0] = dp[1] = 1;
    int ans = 0;
    for(int i = 1; i < n; ++i){
        add(dp[i + 2], dp[i + 1]);
        add(dp[i + 1], dp[i]);
        add(dp[i + 2], dp[i - 1]);
        add(ans, mul(dp[i - 1], mul(n, i)));
        add(ans, mul(dp[i - 1], mul(n - 1, n - i - 1)));
    }
    add(ans, dp[n]);
    add(ans, mul(dp[n - 1], n - 1));
    cout << ans << endl;
}