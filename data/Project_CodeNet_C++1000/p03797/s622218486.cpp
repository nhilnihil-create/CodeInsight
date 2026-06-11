#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, M;
    cin >> N >> M;

    if (N >= M / 2) {
        cout << (M / 2) << endl;
        return;
    }

    long long ans = N;
    M -= 2 * N;
    ans += M / 4;
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
