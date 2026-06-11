#include <bits/stdc++.h>
using namespace std;

void prime_factor(const int n, map<int, long long>& mp) {
    int n_ = n;
    for (int i = 2; i * i <= n; ++i) {
        int cnt = 0;
        while (n_ % i == 0) {
            ++cnt;
            n_ /= i;
        }
        if (cnt) mp[i] += cnt;
    }
    if (n_ != 1) mp[n_] += 1;
}

int main() {
    int N;  cin >> N;
    map<int, long long> mp;
    for (int i = 1; i <= N; ++i) {
        prime_factor(i, mp);
    }
    const int MOD = 1e9 + 7;
    long long ans = 1;
    for (auto e : mp) {
        ans = ans * (e.second + 1) % MOD;
    }
    cout << ans << endl;
}
