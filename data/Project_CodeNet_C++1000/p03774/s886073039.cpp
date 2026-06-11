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
#define rrep(i,n) for(int i = n -1;i >= 1;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
ll n, m, x = 0, y,z,w,h, sum= 0, ans = 0;
int main(void) {
    cin >> n >> m; vector<int> a(n),b(n),c(m),d(m);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, m) cin >> c[i] >> d[i];
    ll dist = INF;
    rep(i, n) {
        dist = INF;
        rep(j, m) {
            if (dist > abs(a[i] - c[j]) + abs(b[i] - d[j])) {
                dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }
}