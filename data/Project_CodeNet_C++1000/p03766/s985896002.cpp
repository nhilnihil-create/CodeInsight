#include <bits/stdc++.h>
using namespace std;

int main(){
    constexpr long MOD = 1000000007;
    long N;
    cin >> N;
    long dp{N};
    vector<long> sum(4, (N - 1) * N % MOD);
    sum[0] = 0;
    for(long i = 3; i != N + 3; ++i){
        sum[3] = sum[2] - 1 + ((dp += sum[0]) %= MOD);
        swap(sum[1], sum[0]);
        swap(sum[1], sum[2]);
        swap(sum[3], sum[2]);
    }
    cout << dp << endl;
    return 0;
}