#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
int main() {
    int N, M;
    cin >> N >> M;
    if(1 < abs(N - M)) {
        cout << 0 << endl;
        return 0;
    }
    long long int n = 1;
    long long int m = 1;
    for(int i = 1; i <= N; i++) {
        n *= i;
        n %= mod;
    }
    for(int i = 1; i <= M; i++) {
        m *= i;
        m %= mod;
    }
    long long int result = n * m % mod;
    if(N == M) {
        result *= 2;
        result %= mod;
    }
    cout << result << endl;
    return 0;
}