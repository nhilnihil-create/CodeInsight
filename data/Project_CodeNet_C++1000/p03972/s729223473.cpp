#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int w, h;
    cin >> w >> h;
    vector<P> a(w+h);
    ll ans = 0;
    rep(i,w){
        ll p;
        cin >> p;
        a[i] = P(p, 0);
        ans += p * (h + 1);
    }
    for(int i = w; i < w + h; ++i){
        ll q;
        cin >> q;
        a[i] = P(q, 1);
        ans += q * (w + 1);
    }
    sort(a.begin(), a.end());
    int cnt[2] = {};
    rep(i,w+h){
        P x = a[i];
        if(x.second == 0){
            ++cnt[0];
            ans -= x.first * cnt[1];
        }
        else{
            ++cnt[1];
            ans -= x.first * cnt[0];
        }
    }
    cout << ans << endl;
    return 0;
}
