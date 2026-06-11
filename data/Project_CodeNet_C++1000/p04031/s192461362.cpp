#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<int> a(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int ans = 40000000;
    for (int target = -100; target <= 100; ++target) {
        int cost = 0;
        for (int i = 0; i < N; ++i) {
            cost += (a[i] - target) * (a[i] - target);
        }
        ans = min(ans, cost);
    }

    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
