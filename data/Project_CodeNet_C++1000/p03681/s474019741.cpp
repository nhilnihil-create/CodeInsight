#include <iostream>
using namespace std;
const int MOD = 1000000007;

long long mul(long long &a, long long b) {
    a *= b;
    if (a >= MOD) a %= MOD;
}

int main() {
    long long N, M; cin >> N >> M;
    if (abs(N - M) > 1) { 
        cout << 0 << endl;
        return 0;
    }
    long long ans = 1;
    for (int i = 1; i <= N; i++) mul(ans, i);
    for (int i = 1; i <= M; i++) mul(ans, i);
    if (N == M) mul(ans, 2);
    cout << ans << endl;
}