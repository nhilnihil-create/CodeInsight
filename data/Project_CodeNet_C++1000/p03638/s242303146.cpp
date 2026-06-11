#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
    ll h, w, n; cin >> h >> w >> n;
    vector <vector <ll>> v(h, vector <ll> (w));
    ll loc_h = 0, loc_w = 0;
    rep(i, n) {
        ll a; cin >> a;
        rep(j, a) {
            v.at(loc_h).at(loc_w) = i+1;
            if (loc_h%2 && loc_w==0) loc_h++;
            else if (loc_h%2==0 && loc_w==w-1) loc_h++;
            else if (loc_h%2) loc_w--;
            else loc_w++;
        }
    }
    rep(i, h) {
        rep(j, w) {
            if (j) cout << ' ' << v.at(i).at(j);
            else cout << v.at(i).at(j);
        }
        cout << endl;
    }
}