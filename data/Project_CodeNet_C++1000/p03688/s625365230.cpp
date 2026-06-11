#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> cnt;
    rep(i, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    auto itb = cnt.begin();
    auto itl = cnt.end(); itl--;
    ll minv = itb->first;
    ll minc = itb->second;
    ll maxv = itl->first;
    ll maxc = itl->second;
    ll diff = maxv - minv;
    if (sz(cnt) > 2) {
        cout << "No" << endl;
    }
    else if (diff > 1) {
        cout << "No" << endl;
    }
    else if ((diff == 0) && (minv != (n - 1)) && ((2 * minv) > n)) {
        cout << "No" << endl;
    }
    else if ((diff == 1) && (minc >= maxv) || ((2 * (maxv - minc)) > maxc)) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    return 0;
}
