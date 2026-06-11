#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::vector<long long> A) {
    map<ll, bool> nummap;
    ll ans = 0;
    rep(i, N) {
        if (nummap[A[i]] == false) {
            nummap[A[i]] = true;
            ans++;
        } else {
            nummap[A[i]] = false;
            ans--;
        }
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
