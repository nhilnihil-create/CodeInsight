#include "bits/stdc++.h"

using namespace std;

long long N, A, B;
vector<long long> X;

void Main() {
    cin >> N >> A >> B;
    X = vector<long long>(N, 0);
    for (long long i = 0; i < N; ++i) {
        cin >> X[i];
    }

    long long ans = 0LL;
    for (long long i = 0; i < N - 1; ++i) {
        long long dist = X[i + 1] - X[i];
        ans += min(dist * A, B);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
