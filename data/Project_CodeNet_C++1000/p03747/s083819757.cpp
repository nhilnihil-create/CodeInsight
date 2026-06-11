
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    ll N, L, T;
    cin >> N >> L >> T;

    vector<ll> X(N), W(N);
    REP(i, N) cin >> X[i] >> W[i];

    vector<ll> Y(N);
    ll Y0;
    REP(i, N) {
        if (W[i] == 1) {
            Y[i] = (X[i] + T) % L;
        } else {
            Y[i] = ((X[i] - T) % L + L) % L;
        }

        if (i == 0) Y0 = Y[i];
    }

    sort(ALL(Y));

    ll cnt = 0;
    FOR(i, 1, N) {
        if (W[0] == W[i]) continue;

        if (W[0] == 1) {
            if (T * 2 < abs(X[i] - X[0])) continue;

            ll remain = T * 2 - abs(X[i] - X[0]);
            cnt += 1 + remain / L;

        } else {
            if (T * 2 < L - abs(X[i] - X[0])) continue;

            ll remain = T * 2 - L + abs(X[i] - X[0]);
            cnt -= 1 + remain / L;
        }
    }

    debug(cnt)

    cnt = (cnt % N + N) % N;


    int idx = -1;
    REP(i, N) if (Y[i] == Y0) {
        idx = i;
        if (W[0] == 2) break;
    }

    debug(cnt, idx)
    cnt = ((idx - cnt) % N + N) % N;

    FOR(i, cnt, N) cout << Y[i] << endl;
    FOR(i, 0, cnt) cout << Y[i] << endl;

}
