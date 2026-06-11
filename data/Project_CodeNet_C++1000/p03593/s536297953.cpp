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
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    map<char, ll> cnt;
    rep(i, h) rep(j, w) cnt[a[i][j]]++;
    string s = "";
    rep(i, w) s += "*";
    vector<string> cur(h);
    rep(i, h) cur[i] = s;
    priority_queue<ll> pq;
    rep(i, h) {
        rep(j, w) {
            ll cnt = 0;
            if (cur[i][j] != '*') continue;
            cur[i][j] = 'S';
            cnt++;
            if (cur[h - 1 - i][j] == '*') {
                cur[h - 1 - i][j] = 'S';
                cnt++;
            }
            if (cur[h - 1 - i][w - 1 - j] == '*') {
                cur[h - 1 - i][w - 1 - j] = 'S';
                cnt++;
            }
            if (cur[i][w - 1 - j] == '*') {
                cur[i][w - 1 - j] = 'S';
                cnt++;
            }
            pq.push(cnt);
        }
    }
    priority_queue<ll> cntpq;
    for(auto x : cnt) cntpq.push(x.second);
    while(!pq.empty()) {
        ll v = cntpq.top(); cntpq.pop();
        ll x = pq.top(); pq.pop();
        if (v < x) {
            cout << "No" << endl;
            return 0;
        }
        v -= x;
        if (v > 0) cntpq.push(v);
    }
    cout << "Yes" << endl;
    return 0;
}
