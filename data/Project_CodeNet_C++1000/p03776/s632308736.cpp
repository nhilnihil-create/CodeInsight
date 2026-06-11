#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

ll dp[101][101];

void COMinit() {
    rep(i, 101) {
        dp[i][0] = 1;
        repd(j, 1, i + 1) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}
int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    map<ll, ll> cnt;

    rep(i, N) {
        cin >> v[i];
        cnt[v[i]]++;
    }

    sort(all(v));
    reverse(all(v));

    COMinit();
    long double ct;
    ll ans = 0;
    for (ll j = A; j <= B; j++) {
        map<ll, ll> l;
        ll res = 1;
        long double ave = 0;
        rep(i, j) {
            l[v[i]]++;
            ave += v[i];
        }
        ave /= j;
        if (j == A) ct = ave;
        else if (ave != ct) break;
        for (auto itr = l.begin(); itr != l.end(); itr++) {
            res *= dp[cnt[itr->first]][itr->second];
        }
        ans += res;
    }

    cout << fixed << setprecision(7) << ct << endl;
    cout << ans << endl;

    return 0;
}