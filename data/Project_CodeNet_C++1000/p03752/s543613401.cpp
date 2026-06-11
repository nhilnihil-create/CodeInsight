// https://qiita.com/e869120/items/eb50fdaece12be418faa

#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n, 0);
    rep(i, n) {
        cin >> a[i];
    }

    ll res = LINF;
    for (int bit = 0; bit < (1 << n); bit++) {
        ll num = 0;
        ll sum = 0;
        ll minh = 0;
        rep(i, n) {
            if (a[i] > minh) {
                num++;
                minh = a[i];
                continue;
            }
            if ((bit >> i) & 1) {
                minh = minh + 1;
                sum += minh - a[i];
                num++;
            }
        }
        if (num >= k) {
            chmin(res, sum);
        }
    }

    cout << res << endl;

    return 0;
}