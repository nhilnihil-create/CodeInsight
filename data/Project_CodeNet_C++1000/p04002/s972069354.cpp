#include <bits/stdc++.h>
using namespace std;

int main() {
    long h, w, n;
    cin >> h >> w >> n;
    unordered_map<long, int> counter;
    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        a--; b--;
        for (long i = max(1l, a - 1); i <= min(h - 2, a + 1); i++) {
            for (long j = max(1l, b - 1); j <= min(w - 2, b + 1); j++) {
                if (counter.find(w * i + j) == counter.end())
                    counter[w * i + j] = 0;
                counter[w * i + j]++;
            }
        }
    }
    int count[10];
    fill(count, count + 10, 0);
    for (auto p: counter) {
        count[p.second]++;
    }
    cout << (h * w - 2 * (h + w - 2) - counter.size()) << endl;
    for (int i = 1; i <= 9; i++) {
        cout << count[i] << endl;
    }
    return 0;
}
