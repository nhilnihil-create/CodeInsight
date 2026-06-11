#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<vector<unsigned long>> dp(401, vector<unsigned long>(401, numeric_limits<unsigned long>::max()));
    dp[0][0] = 0;
    for(unsigned long i{0}, a, b, c; i < N; ++i){
        cin >> a >> b >> c;
        for(unsigned long j{401 - a}; j--;)for(unsigned long k{401 - b}; k--;)if(~dp[j][k])dp[j + a][k + b] = min(dp[j + a][k + b], dp[j][k] + c);
    }
    unsigned long ans{numeric_limits<unsigned long>::max()};
    for(unsigned long i{1}; i * Ma <= 400 && i * Mb <= 400; ++i)ans = min(ans, dp[i * Ma][i * Mb]);
    cout << static_cast<long>(ans) << endl;
    return 0;
}