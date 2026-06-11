#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, long long C, long long K, std::vector<long long> T) {
    sort(T.begin(), T.end());
    ll ans = 1;
    ll beforeT = T[0];
    ll beforeC = 1;
    for (ll i = 1; i < N; i++) {
        if (((T[i] - beforeT) > K) || ((beforeC + 1) > C)) {
            ans++;
            beforeT = T[i];
            beforeC = 1;
        } else {
            beforeC += 1;
        }
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long C;
    scanf("%lld", &C);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> T(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &T[i]);
    }
    solve(N, C, K, std::move(T));
    return 0;
}
