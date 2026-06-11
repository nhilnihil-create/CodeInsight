#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long x;
    cin >> x;

    long long k = x / 11LL;
    long long l = x % 11LL;
    long long ans = 2LL * k;
    if (l == 0LL) {
        ans += 0LL;
    }
    else if (0LL < l && l <= 6LL) {
        ans += 1LL;
    }
    else {
        ans += 2LL;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
