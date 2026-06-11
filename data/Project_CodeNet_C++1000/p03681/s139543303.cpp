#include <iostream>
using namespace std;
 
int MOD = 1000000000 + 7;
 
long long solver(long long N) {
    long long res = N;
    while (N!=1) {
        N--;
        res = res * N;
        res = res % MOD;
    }
    return res;
}
 
int main()
{
    long long N, M, ans;
    cin >> N >> M;
    long long res1 = solver(N);
    long long res2 = solver(M);
    if (N==M) {
        ans = res1 * res2;
        ans %= MOD;
        ans *= 2;
        ans %= MOD;
    } else if (N==M-1 || N-1==M) {
        ans = res1 * res2;
        ans %= MOD;
    } else {
        ans = 0;
    }
    cout << ans << endl;
}