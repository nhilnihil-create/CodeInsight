#include <bits/stdc++.h>
using namespace std;

int main(){
    constexpr long MOD = 1000000007;
    long N;
    cin >> N;
    long dp{N};
    vector<long> sum(4, (N - 1) * N % MOD);
    sum[0] = 0;
    for(long i = 3, j = 2; i != N + 3; ++i, ++j)sum[i & 3] = (sum[j & 3] - 1 + (dp += sum[(j ^ 2) & 3])) % MOD;
    cout << dp % MOD << endl;
    return 0;
}