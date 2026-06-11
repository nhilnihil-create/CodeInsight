#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        ans += (r + 1) - l;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
