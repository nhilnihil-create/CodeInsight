#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::vector<long long> a) {
    set<ll> colorset;
    ll cnt = 0;
    rep(i, N) {
        ll r = a[i];
        if (r >= 3200) {
            cnt++;
        } else {
            colorset.insert(r / 400);
        }
    }
    if (colorset.size() == 0) {
        cout << 1 << " " << cnt << endl;
    } else {
        cout << colorset.size() << " " << (ll)colorset.size() + cnt << endl;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
