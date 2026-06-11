#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<ll, ll> P;
int main()
{
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    vector<P> value(4);
    value[0] = P(Q * 8, 0); value[1] = P(H * 4, 0);
    value[2] = P(S * 2, 0); value[3] = P(D, 1);
    sort(all(value));
    ll s2 = N / 2;
    ll ans = s2 * value[0].first;
    if (N % 2) {
        ll concent = value[0].first;
        if (value[0].second == 1) {
            concent = value[1].first;
        }
        ans += concent / 2;
    }

    cout << ans << endl;
    return 0;
}