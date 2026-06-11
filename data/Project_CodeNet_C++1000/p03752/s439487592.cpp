// failed to generate code

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i, x) for (int i = 0; i < x; i++)
#define repn(i, x) for (int i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
vector<pair<string, P> > vec;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll res = INF;
    rep(i, 1LL << N) {
        ll maxh = 0, now = 0;
        vector<ll> b(N);
        rep(j, N) {
            if ((i & 1LL << j) && maxh >= a[j]) {
                now += max(maxh + 1 - a[j], 0LL);
                b[j] = maxh + 1;
            } else {
                b[j] = a[j];
            }
            maxh = max(maxh, b[j]);
        }
        ll nowk = 0;
        maxh = 0;
        rep(j, N) {
            if (b[j] > maxh) nowk++;
            maxh = max(maxh, b[j]);
        }
        if (nowk >= K) res = min(res, now);
        // if (now == 4) cout << i << endl;
    }
    cout << res << endl;
}
