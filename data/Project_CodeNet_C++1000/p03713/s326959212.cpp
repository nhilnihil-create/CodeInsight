#include<bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }



int main() {
    ll h,w; cin >> h >> w;
    if(h%3 == 0 || w%3 == 0) {
        cout << 0 << endl;
        return 0;
    }
    // それ以外
    ll ans = LONG_MAX;
    FOR(i,1,h) {
        ll a = w*i;

        // 下半分は横分割版
        ll b = (w/2)*(h-i), c =(w/2)*(h-i);
        if(w%2 == 1) c += (h-i);
        //cout << a << ":" << b << ":" << c << endl;
        chmin(ans, abs(max(max(b, c),a)-min(min(a, b),c)));

        // 下半分も縦分割版
        ll hh = h-i;
        b = (hh/2)*w, c =(hh/2)*w;
        if(hh%2 == 1) c += w;
        //cout << a << ":" << b << ":" << c << endl;
        chmin(ans, abs(max(max(b, c),a)-min(min(a, b),c)));
    }
    FOR(i,1,w) {
        ll a = h*i;
        ll b = (h/2)*(w-i), c =(h/2)*(w-i);
        if(h%2 == 1) c += (w-i);
        //cout << a << ":" << b << ":" << c << endl;
        chmin(ans, abs(max(max(b, c),a)-min(min(a, b),c)));

        ll ww = w-i;
        b = (ww/2)*h, c =(ww/2)*h;
        if(ww%2 == 1) c += h;
        //cout << a << ":" << b << ":" << c << endl;
        chmin(ans, abs(max(max(b, c),a)-min(min(a, b),c)));
    }

    cout << ans << endl;

    return 0;
}
