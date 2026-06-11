#include <bits/stdc++.h>
using namespace std;

long long extgcd(long long a, long long b, long long& x, long long& y){
    long long d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}

const long long MOD = 1e9+7;
long long mod_inv(long long a){
    long long x, y;
    extgcd(a, MOD, x, y);
    return (MOD + x%MOD) % MOD;
}

const long long MAX = 5001;
long long dp[MAX][MAX];

int main(){
    long long i, j, k;
    long long N;
    cin >> N;
    string S;
    cin >> S;
    long long M = S.size();
    dp[0][0] = 1;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            dp[i+1][j+1] = (dp[i+1][j+1] + 2*dp[i][j]) % MOD;
            dp[i+1][max(j-1, 0LL)] = (dp[i+1][max(j-1, 0LL)] + dp[i][j]) % MOD;
        }
    }
    long long inv2 = mod_inv(2);
    long long ans = dp[N][M];
    for(i=0; i<M; i++) ans = ans * inv2 % MOD;
    cout << ans << endl;
    return 0;
}