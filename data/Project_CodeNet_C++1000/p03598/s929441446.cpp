#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, K;
    cin >> N;
    cin >> K;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        ans += 2 * min(abs(K - x), abs(0 - x));
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
