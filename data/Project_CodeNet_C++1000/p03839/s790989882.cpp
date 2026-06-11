#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void _main()
{
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, 0, N) cin >> a[i];
    vector<ll> sum(N + 1), sum2(N + 1);
    sum[0] = sum2[0] = 0;
    rep(i, 0, N)
    {
        sum[i + 1] = sum[i] + a[i];
        sum2[i + 1] = sum2[i] + max(a[i], 0LL);
    }

    ll ans = 0;
    rep(i, 0, N - K + 1)
    {
        // [l, r)
        const int l1 = 0;
        const int r1 = i;
        const int l2 = i;
        const int r2 = i + K;
        const int l3 = i + K;
        const int r3 = N;
        
        ll x = 0, y = 0;
        if (l1 < r1)
        {
            x += sum2[r1] - sum2[l1];
            y += sum2[r1] - sum2[l1];
        }
        x += sum[r2] - sum[l2];
        if (l3 < r3)
        {
            x += sum2[r3] - sum2[l3];
            y += sum2[r3] - sum2[l3];
        }
        chmax(ans, x);
        chmax(ans, y);
    }
    cout << ans << endl;
}
