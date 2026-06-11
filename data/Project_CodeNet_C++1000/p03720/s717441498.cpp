#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[50], b[50];

void solve() {
    int res[51] = {0};
    for (int i = 0; i < M; ++i) {
        res[a[i]]++;
        res[b[i]]++;
    }
    for (int i = 1; i <= N; ++i) {
        printf("%d\n", res[i]);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
    }
    solve();
    return 0;
}