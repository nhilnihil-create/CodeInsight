#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll w, h;
    cin>>w>>h;
    vpii p(w + h);
    rep(i, w) {
        cin >> p[i].first;
    }
    rep(i, h){
        cin>>p[i + w].first;
        p[i + w].second = 1;
    }
    
    sort(all(p));

    ll ans = 0;
    h++; w++;
    rep(i, p.size()) {
        if (p[i].second == 1) {
            ans += w * p[i].first;
            h--;
        } else {
            ans += h * p[i].first;
            w--;
        }
    }

    cout << ans << endl;
    return 0;
}
