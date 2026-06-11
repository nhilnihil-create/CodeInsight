#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll sum = 0;
    ll cnt = 0;
    rep(i, n) {
        if (i % 2 == 0 && a[i] + sum <= 0) {
            cnt += abs(1 - sum - a[i]);
            sum = 1;
        }
        else if (i % 2 == 1 && a[i] + sum >= 0) {
            cnt += abs(-1 - sum - a[i]);
            sum = -1;
        }
        else {
            sum += a[i];
        }
    }

    ll ans = cnt;
    cnt = 0;
    sum = 0;
    rep(i, n) {
        if (i % 2 == 1 && a[i] + sum <= 0) {
            cnt += abs(1 - sum - a[i]);
            sum = 1;
        }
        else if (i % 2 == 0 && a[i] + sum >= 0) {
            cnt += abs(-1 - sum - a[i]);
            sum = -1;
        }
        else {
            sum += a[i];
        }
    }

    cout << min(ans, cnt) << endl;
    return 0;
}