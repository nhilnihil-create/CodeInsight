#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1e9 + 7;
int N;

int main() {
    cin >> N;
    vector<bool> prime(N + 1, false);
    long long ans = 1;
    for (int i = 2; i <= N; i++) {
        bool flag = true;
        for (int j = 2; j < i; j++)
            if (i % j == 0)
                flag = false;
        if (flag)
            prime[i] = true;
    }
    for (int i = 2; i <= N; i++) {
        if(prime[i]) {
            long long res = 0, temp = i;
            while(temp <= N) {
                res += N / temp;
                temp *= i;
            }
            ans *= (res + 1) % MOD;
            ans %= MOD;
        }
    }
    cout << ans % MOD << endl;
    return 0;
}