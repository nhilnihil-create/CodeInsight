#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i * (m - j) + j * (n - i) == k) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
}