#include <bits/stdc++.h>

using namespace std;

int N;
long long a[300000];

void solve() {
    long long num = 0;
    sort(a, a + N * 3, greater<>());
    for (int i = 0; i < N; i++) {
        num += a[2 * i + 1];
    }
    printf("%lld\n", num);
}

int main() {
    cin >> N;
    for (int i = 0; i < N * 3; ++i) cin >> a[i];
    solve();
    return 0;
}