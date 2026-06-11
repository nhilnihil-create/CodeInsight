#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    vector<bool> ok1(N, false), ok2(N, false);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        if (a[i] == 1) ok1[b[i]] = true;
        if (b[i] == N) ok2[a[i]] = true;
    }

    for (int i = 2; i < N; i++) {
        if (ok1[i] && ok2[i]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
