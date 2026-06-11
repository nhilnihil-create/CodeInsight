// https://qiita.com/e869120/items/eb50fdaece12be418faa

#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll start;
    vector<ll> a(n-1);
    rep(i, n) {
        if (i == 0) cin >> start;
        else cin >> a[i-1];
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll res = LINF;
    for (int bit = 0; bit < (1 << n - 1); ++bit) {
        ll maxh = start;
        ll sum = 0;
        ll cnt = 1;
        for (int i = 0; i < n - 1; i++) {
            if (bit & (1 << i)) {
                cnt++;
                if (a[i] <= maxh) {
                    sum += maxh - a[i] + 1;
                    maxh += 1;
                }
                else {
                    sum += 1;
                    maxh = a[i] + 1;
                }
            }
            else {
                if (a[i] > maxh) {
                    cnt++;
                    maxh = a[i];
                }
            }
        }
        if (cnt >= k) chmin(res, sum);
    }

    cout << res << endl;


    return 0;
}