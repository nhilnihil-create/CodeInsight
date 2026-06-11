#include <bits/stdc++.h>

using namespace std;

int N, K;
int l[50];

void solve() {
    sort(l, l + N, greater<int>());
    int num = 0;
    for (int i = 0; i < K; ++i) {
        num += l[i];
    }
    printf("%d\n", num);
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> l[i];
    }
    solve();
    return 0;
}