#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(long long N, long long M_a, long long M_b, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c){
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(500, vector<ll>(500, 1e9)));
    dp[0][0][0] = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < 500;j++){
            for(int k = 0;k < 500;k++){
                dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k]);
                if(j+a[i] >= 500 || k+b[i] >= 500)continue;
                dp[i+1][j+a[i]][k+b[i]] = min(dp[i][j][k] + c[i], dp[i+1][j+a[i]][k+b[i]]);
            }
        }
    }
    ll ans = 1e18;
    for(int i = 0;i < 500;i++){
        for(int j = 0;j < 500;j++){
            if(i == 0 || j == 0){
                if(i == M_a && j == M_b){
                   // cout<<i<<" "<<j<<" "<<dp.back()[i][j]<<endl;
                    ans = min(ans, dp.back()[i][j]);
                }
            }else{
                if(M_a == i / __gcd(i, j) && M_b == j / __gcd(i, j)){
                   // cout<<i<<" "<<j<<" "<<dp.back()[i][j]<<endl;
                    ans = min(ans, dp.back()[i][j]);
                }
            }
        }
    }
    if(ans == 1e9){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M_a;
    scanf("%lld",&M_a);
    long long M_b;
    scanf("%lld",&M_b);
    std::vector<long long> a(N);
    std::vector<long long> b(N);
    std::vector<long long> c(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        scanf("%lld",&c[i]);
    }
    solve(N, M_a, M_b, std::move(a), std::move(b), std::move(c));
    return 0;
}
