/**
 *    author:  FromDihPout
 *    created: 2020-06-24
**/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<bool> composite(n + 1);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (composite[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j <= n; j += i) {
            composite[j] = true;
        }
    }
    
    int prime_cnt = (int) primes.size();
    vector<int> factors(prime_cnt);
    for (int i = 2; i <= n; i++) {
        int num = i;
        for (int j = 0; j < prime_cnt; j++) {
            while (num % primes[j] == 0) {
                factors[j]++;
                num /= primes[j];
            }
        }
    }
    
    int ans = 1;
    for (auto i : factors) {
        ans = (long long) ans * (i + 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}