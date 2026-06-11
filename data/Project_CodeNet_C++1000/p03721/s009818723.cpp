#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, long long K, std::vector<long long> a, std::vector<long long> b) {
    vector<ll> bucket(1e5 + 1);
    rep(i, N) { bucket[a[i]] += b[i]; }

    ll prevcnt = 0;
    for (ll i = 1; i < 1e5 + 1; i++) {
        if (prevcnt < K && K <= prevcnt + bucket[i]) {
            cout << i << endl;
            return;
        } else {
            prevcnt += bucket[i];
        }
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> a(N);
    std::vector<long long> b(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
    }
    solve(N, K, std::move(a), std::move(b));
    return 0;
}
