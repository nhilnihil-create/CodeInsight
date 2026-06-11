#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    ll N;
    cin >> N;

    ll ans = 1, bCnt = 0;
    FOR(i, 2, N + 1) {
        ll tmp = i, cnt = 0;
        while(tmp % 2 == 0) {
            ++cnt;
            tmp /= 2;
        }

        if(cnt > bCnt) {
            bCnt = cnt;
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}