#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;

int main(){
    ll h, w;
    cin >> h >> w;
    ll ans = INF_LL;
    ll tmp_max = 0, tmp_min = INF_LL;

    /* h */
    REPN(i, 1, h) {
        ll a, b, c;
        int nokori_h = h - i;
        a = i * w;

        /* 縦に切る */
        if(w % 2 == 0) {
            b = c = nokori_h * w/2;
        } else {
            b = nokori_h * (w+1)/2;
            c = nokori_h * (w-1)/2;
        }

        tmp_max = max(a, b);
        tmp_min = min(a, c);
        ans = min(ans, tmp_max - tmp_min);

        /* 真横に切る */
        if(nokori_h == 1) continue;
        if(nokori_h % 2 == 0) {
            b = c = nokori_h * w / 2;
        } else {
            b = w * (nokori_h+1) / 2;
            c = w * (nokori_h-1) / 2;
        }

        tmp_max = 0, tmp_min = INF_LL;        
        tmp_max = max(a, b);
        tmp_min = min(a, c);
        ans = min(ans, tmp_max - tmp_min);
    }


    /* w */
    REPN(i, 1, w) {
        ll a, b, c;
        int nokori_w = w - i;
        a = i * h;

        /* 縦に切る */
        if(h % 2 == 0) {
            b = c = nokori_w * h/2;
        } else {
            b = nokori_w * (h+1)/2;
            c = nokori_w * (h-1)/2;
        }

        tmp_max = max(a, b);
        tmp_min = min(a, c);
        ans = min(ans, tmp_max - tmp_min);

        /* 真横に切る */
        if(nokori_w == 1) continue;
        if(nokori_w % 2 == 0) {
            b = c = nokori_w * h / 2;
        } else {
            b = h * (nokori_w+1) / 2;
            c = h * (nokori_w-1) / 2;
        }

        tmp_max = 0, tmp_min = INF_LL;        
        tmp_max = max(a, b);
        tmp_min = min(a, c);
        ans = min(ans, tmp_max - tmp_min);
    }

    cout << ans << endl;

    return 0;
}
