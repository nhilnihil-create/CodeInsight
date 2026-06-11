#include <bits/stdc++.h>
using namespace std;

int cnt_digits(int64_t x) {
    int digits = 0;
    while (x > 0) {
        x /= 10;
        digits++;
    }
    return digits;
}

int main() {
    int64_t N;
    cin >> N;

    int ans = cnt_digits(N);
    for (int64_t A = 1LL; A * A <= N; A++) {
        if (N % A != 0) continue;
        int64_t B = N / A;

        int maximum = max(cnt_digits(A), cnt_digits(B));
        if (ans > maximum) ans = maximum;
    }
    cout << ans << endl;
}