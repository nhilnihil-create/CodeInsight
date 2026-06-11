#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    vector<ll> a(n, 0);
    rep1(i, n) cin >> a[i];
    vector<vector<ll> > color(h, vector<ll>(w));
    ll ndx = 0;
    for (ll i=0; i<(h); i++){
        for (ll j=0; j<(w); j++){
            ll x, y;
            x = i;
            if (x%2==0) y = j;
            else y = w-1 - j; 
            color[x][y] = ndx+1;
            a[ndx]--;
            if (a[ndx]==0) ndx++;
        }
    }
    for (ll i=0; i<(h); i++){
        for (ll j=0; j<(w); j++){
            if (j<w-1) cout << color[i][j] << " ";
            else cout << color[i][j] << endl;
        }
    }
    //printf("%.12f", ans);
}