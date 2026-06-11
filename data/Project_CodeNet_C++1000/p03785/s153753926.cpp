#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N, C, K;
    cin >> N >> C >> K;
    int T[N];
    for(int i = 0; i < N; i++) cin >> T[i];
    sort(T, T + N);
    int ans = 0, people = 1, first = T[0];
    for(int i = 1; i < N; i++) {
        if(T[i] - first > K || people == C) {
            ans++;
            people = 1;
            first = T[i];
        } else
            people++;
    }

    cout << ans + 1 << "\n";
    return 0;
}