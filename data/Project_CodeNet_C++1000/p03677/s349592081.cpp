#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)

ll count(ll a, ll b, int M) {
    return b - a + (a <= b ? 0 : M);
}

int main() {
    int N, M; cin >> N >> M;
    vl a(N);
    rep(i,N) cin >> a[i];

    vl imos(2*M+1, 0);
    rng(i,1,N) {
        int l = a[i-1]+2;
        int r = a[i]+1+(a[i-1]<a[i]?0:M);
        imos[l]++;
        imos[r]--;
    }
    rep(i,2*M) imos[i+1] += imos[i];
    rng(i,1,N) {
        int l = a[i-1]+2;
        int r = a[i]+1+(a[i-1]<a[i]?0:M);
        imos[r] -= r - l;
    }
    rep(i,2*M) imos[i+1] += imos[i];

    ll fav = 1, mx = -1;
    rng(i,1,M+1) {
        imos[i] += imos[i+M];
        if (imos[i] > mx) {
            mx = imos[i];
            fav = i;
        }
    }
    ll ans = 0;
    rng(i,1,N) {
        ans += min(count(a[i-1], a[i], M), count(fav, a[i], M) + 1);
    }
    cout << ans << endl;
    return 0;
}
