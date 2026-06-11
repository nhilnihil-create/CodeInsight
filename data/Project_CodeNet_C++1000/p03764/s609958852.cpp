#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 1000;
const int mod = 1e9 + 7;
long long s[maxn], t[maxn];
long long ans1 = 0, ans2 = 0;

long long fun(long long a, long long n) {
    long long sum = 0;
    sum = (n - a) * a % mod;
    return sum;
}

int main() {
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
    }
    for (int i = 1; i + 1 <= n; i++) {
        if (i == 1 || i + 1 == n) {
            ans1 = (ans1 + ((s[i + 1] - s[i]) % mod) * (n - 1)) % mod;
        } else {
            ans1 = (ans1 + ((s[i + 1] - s[i]) % mod) * fun(i, n)) % mod;
        }
    }
    for (int i = 1; i + 1 <= m; i++) {
        if (i == 1 || i + 1 == m) {
            ans2 = (ans2 + ((t[i + 1] - t[i]) % mod) * (m - 1)) % mod;
        } else {
            ans2 = (ans2 + ((t[i + 1] - t[i]) % mod) * fun(i, m)) % mod;
        }
    }
    cout << (ans1 * ans2) % mod << endl;
    return 0;
}