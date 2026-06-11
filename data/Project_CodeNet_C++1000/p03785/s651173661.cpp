#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, C, K; cin >> N >> C >> K;
    int T[N];
    for (int i = 0; i < N; i++) cin >> T[i];
    sort(T, T + N);

    int ans = 0, pas = 0, minT = T[0];
    for (int i = 0; i < N; i++) {
        if (pas == C) { ans++; pas = 0; minT = T[i]; }
        if (minT <= T[i] && T[i] <= minT + K) pas++;
        else { ans++; pas = 1; minT = T[i]; }
        if (i == N - 1) {
            if (pas > 0) ans++;
        } 
    }
    cout << ans << endl;
}