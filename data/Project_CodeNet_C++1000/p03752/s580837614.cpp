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
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    ll ans = INF;
    rep(bit, 1 << (N - 1)) {
        int c = 0;
        ll ct = a[0];
        ll res = 0;
        rep(i, N - 1) {
            if ((bit >> i) & 1) {
                res += max(0LL, ct - a[i + 1] + 1);
                ct = max(ct + 1, a[i + 1]);
                c++;
            }
            else {
                if (ct < a[i + 1]) {
                    c++;
                    ct = a[i + 1];
                }
            }
        }
        if (c >= K - 1) {
            chmin(ans, res);
        }
    }

    cout << ans << endl;
    return 0;
}