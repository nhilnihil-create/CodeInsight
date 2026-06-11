#include "bits/stdc++.h"

using namespace std;

long long lcm(long long a, long long b) {
    long long g = __gcd(a, b);
    return (a / g) * b;
}

void Main() {
    int N;
    cin >> N;
    vector<long long> T(N, 0LL);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    if (N == 1) {
        cout << T[0] << endl;
        return;
    }
    long long ans = lcm(T[0], T[1]);
    for (int i = 2; i < N; ++i) {
        ans = lcm(ans, T[i]);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
