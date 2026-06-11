#include <bits/stdc++.h>
using namespace std;

int main(){
    constexpr unsigned long MOD = 1000000007;
    unsigned long N;
    cin >> N;
    unsigned long dp{N};
    vector<unsigned long> sum(N + 3, (N - 1) * N % MOD);
    sum[0] = 0;
    for(unsigned long i = 3; i != N + 3; ++i)sum[i] = (sum[i - 1] - 1 + ((dp += sum[i - 3]) %= MOD)) % MOD;
    cout << dp << endl;
    return 0;
}