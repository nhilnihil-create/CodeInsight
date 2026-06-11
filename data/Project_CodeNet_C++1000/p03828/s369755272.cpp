#include<iostream>
#include<cstring>

using namespace std;

const int MOD = 1e9 + 7;
int N;
char *M;

void init(int n = 8) {
    M = new char[(n + 7) / 8];
    memset(M, 0, (n + 7) / 8);
}

void set(int n) {
    M[n >> 3] |= (0x80 >> (n & 0x07));
}

bool test(int n) {
    return M[n >> 3] & (0x80 >> (n & 0x07));
}

void prime_set(int n) {
    set(0); set(1);
    for (int i = 2; i * i <= n; i++)
        if( !test(i) )
            for (int j = i * i; j <= n; j += i)
                set(j);
}

int main() {
    cin >> N;
    long long ans = 1;
    init(N);
    prime_set(N);
    for (int i = 2; i <= N; i++) {
        if(!test(i)) {
            long long res = 0;
            for (int temp = i; temp <= N; temp *= i)
                res += N / temp;
            ans *= (res + 1) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
