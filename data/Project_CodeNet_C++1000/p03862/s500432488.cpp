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
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    ll ans = 0;
    repd(i, 1, N) {
        if (a[i] + a[i - 1] > x) {
            ans += a[i] + a[i - 1] - x;
            a[i] = max(0LL, a[i] - (a[i] + a[i - 1] - x));
        }
    }

    cout << ans << endl;
    return 0;
}