#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, K;
    cin >> N >> K;

    int ans = K;
    for (int i = 1; i < N; ++i) {
        ans *= K - 1;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
