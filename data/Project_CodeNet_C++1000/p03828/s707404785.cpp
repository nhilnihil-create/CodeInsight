#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;

    const int MOD = 1000000007;
    vector<long long> ex(N+1, 0); // exp[p] := p の指数
    for (long long n = 2; n <= N; ++n) {
        // n を素因数分解
        long long n2 = n;
        for (long long a = 2; a <= n2; ++a) {
            while (n2 % a == 0) {
                ex[a]++;
                n2 /= a;
            }
        }
    }
    long long res = 1;
    for (int p = 2; p <= N; ++p) {
        res *= ex[p] + 1; // 約数の個数は (exp + 1) の積
        res %= MOD;
    }
    cout << res << endl;
}
