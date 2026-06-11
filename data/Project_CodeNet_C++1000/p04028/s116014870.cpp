#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return ((ll)a*b)%MOD;
}

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int inv(int x){
    return pw(x, MOD-2);
}

int dp[5005][5005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = s.size();
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        dp[i][0] = add(dp[i-1][0], dp[i-1][1]);
        for(int j=1; j<=n+1; j++){
            dp[i][j] = add(mul(2, dp[i-1][j-1]), dp[i-1][j+1]);
        }
    }
    cout << mul(dp[n][m], inv(pw(2, m))) << "\n";
    return 0;
}
