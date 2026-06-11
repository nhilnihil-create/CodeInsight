#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long W, long long H, long long N, std::vector<long long> x, std::vector<long long> y,
           std::vector<long long> a) {
    ll minX = 0, minY = 0, maxX = W, maxY = H;
    rep(i, N) {
        switch (a[i]) {
            case 1: minX = max(minX, x[i]); break;
            case 2: maxX = min(maxX, x[i]); break;
            case 3: minY = max(minY, y[i]); break;
            case 4: maxY = min(maxY, y[i]); break;
        }
    }
    if (minX > maxX || minY > maxY) {
        cout << 0 << endl;
    } else {
        cout << (maxX - minX) * (maxY - minY) << endl;
    }
}

int main() {
    long long W;
    scanf("%lld", &W);
    long long H;
    scanf("%lld", &H);
    long long N;
    scanf("%lld", &N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &x[i]);
        scanf("%lld", &y[i]);
        scanf("%lld", &a[i]);
    }
    solve(W, H, N, std::move(x), std::move(y), std::move(a));
    return 0;
}
