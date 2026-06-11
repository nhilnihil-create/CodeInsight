#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define PI (acos(-1.0))
#define MODN 1000000007
#define MODN2 998244353
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    int n,p;
    cin >> n >> p;

    vector<int> a(n);

    rep(i, n){
        cin >> a[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(2));

    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            dp[i + 1][0] = dp[i][0] * 2;
            dp[i + 1][1] = dp[i][1] * 2;
        }else{
            dp[i + 1][0] = dp[i][0] + dp[i][1];
            dp[i + 1][1] = dp[i][0] + dp[i][1];
        }
    }

    cout << dp[n][p] << endl;
    return 0;
}
