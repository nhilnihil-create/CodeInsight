#include <bits/stdc++.h>
using namespace std;

int main(){
    constexpr long MOD = 1000000007;
    long N;
    cin >> N;
    long dp{N};
    vector<long> sum(N + 3, (N - 1) * N % MOD);
    sum[0] = 0;
    for(long i = 3; i != N + 3; ++i)sum[i] = (sum[i - 1] - 1 + (dp += sum[i - 3])) % MOD;
    cout << dp % MOD << endl;
    return 0;
}