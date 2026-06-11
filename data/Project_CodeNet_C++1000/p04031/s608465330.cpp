#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int N;
    cin >> N;
    vl A(N);
    rep(i, N) {
        cin >> A[i];
    }


    ll ans = LINF;
    for (ll i = -100; i <= 100; i++) {
        ll tmp = 0;
        // iに書き換える
        rep(j, N) {
            ll x = (i - A[j]) * (i - A[j]);
            tmp += x;
        }

        ans = min(ans, tmp);
    }

    cout << ans << endl;
}