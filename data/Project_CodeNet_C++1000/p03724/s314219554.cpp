#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> cnt(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++; cnt[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (cnt[i] % 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}