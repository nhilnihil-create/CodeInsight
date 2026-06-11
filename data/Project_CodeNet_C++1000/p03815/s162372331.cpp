#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long x;
    cin >> x;

    long long ans = 0LL;
    if (x <= 6) {
        ans += 1;
    }
    else if (x <= 11) {
        ans += 2;
    }
    else { // 11 < x
        ans += 2 * (x / 11LL);
        long long res = x % 11;
        if (0 < res && res <= 6) {
            ans += 1;
        }
        else if (6 < res) {
            ans += 2;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
