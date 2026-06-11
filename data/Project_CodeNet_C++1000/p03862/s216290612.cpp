#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, x;
    cin >> N >> x;
    vector<long long> a(N, 0);
    for (long long i = 0; i < N; ++i) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] > x) {
            ans += a[i] - x;
            a[i] = x;
        }
    }

    for (int i = 1; i < N; ++i) {
        if (a[i - 1] + a[i] > x) {
            long long diff = a[i - 1] + a[i] - x;
            ans += diff;
            a[i] -= diff;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
