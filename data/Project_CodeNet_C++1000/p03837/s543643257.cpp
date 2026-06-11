#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
int n, m, x, y;ll z = 0, w, h, sum = 0, ans = 0;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
struct Corr {
    ll x;
    ll y;
    ll z;
};
int main(void) {
    cin >> n >> m;
    ll dp[110][110]; vector<Corr> a(m);
    Fill(dp, INF);
    rep(i, m) {
        cin >> x >> y >> z;
        x--; y--;
        dp[x][y] = z;
        dp[y][x] = z;
        a[i] = { x,y,z };
    }
    rep(i, n) dp[i][i] = 0;
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    rep(i, m) {
        bool f = 0;
        rep(j, n) {
            if (dp[j][a[i].x] + a[i].z == dp[j][a[i].y]) {
                f = 1; break;
            }
            if (dp[j][a[i].y] + a[i].z == dp[j][a[i].x]) {
                f = 1; break;
            }
        }
        if (!f) ans++;
    }cout << ans << endl;
}