#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, K, a;
    cin >> N >> K;
    vector<long long> p(N + 1), s(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a > 0) {
            p.at(i + 1) = p.at(i) + a;
        } else {
            p.at(i + 1) = p.at(i);
        }
        s.at(i + 1) = s.at(i) + a;
    }
    long long ans = 0;
    for (int i = 0; i < N - K + 1; i++) {
        long long score = p.at(N) - p.at(K + i) + p.at(i) + max(s.at(K + i) - s.at(i), 0LL);
        ans = max(ans, score);
    }
    cout << ans << endl;
}