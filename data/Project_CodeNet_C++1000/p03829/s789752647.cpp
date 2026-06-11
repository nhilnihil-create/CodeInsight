#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
int main()
{
    ll N, A, B;
    cin >> N >> A >> B;

    vector<ll> X(N);
    rep(i, N) cin >> X[i];

    ll ans = 0;
    rep(i, N - 1) {
        if ((X[i + 1] - X[i]) * A > B) ans += B;
        else ans += (X[i + 1] - X[i]) * A;
    }

    cout << ans << endl;
    return 0;
}