#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M;
    cin >> N >> M;

    vec<int> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    vec<int> c(M), d(M);
    rep(i, M) cin >> c[i] >> d[i];

    auto mhtn = [&](int x0, int y0, int x1, int y1) {
        return abs(x0 - x1) + abs(y0 - y1);
    };

    vec<int> ans(N,1e9+7);

    rep(i,N)rep(j,M){
        int diffj = mhtn(a[i],b[i],c[j],d[j]);
        if(ans[i] == 1e9+7) ans[i] = j;
        else {
            int diffb = mhtn(a[i],b[i],c[ans[i]],d[ans[i]]);
            if(diffb > diffj) ans[i] = j;
        }
    }
    rep(i,N) cout << ans[i]+1 << '\n';
}
