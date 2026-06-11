#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;  cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    long long ans = 1LL << 60;
    for (int i = 0; i < (1 << N); ++i) {
        bitset<15> bset(i);
        int color = 0;
        for (int j = 0; j < N; ++j) if (bset[j]) ++color;
        if (color >= K) {
            long long cost = 0;
            int highest = 0;
            for (int j = 0; j < N; ++j) {
                if (bset[j] && a[j] <= highest) {
                    cost += highest - a[j] + 1;
                    ++highest;
                }
                else {
                    highest = max(highest, a[j]);
                }
            }
            ans = min(ans, cost);
        }
    }

    cout << ans << endl;
}
