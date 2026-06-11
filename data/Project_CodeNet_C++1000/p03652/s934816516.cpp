#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 8;
const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;
#define Pint pair<int, int>
#define rng(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rnr(i, a, b) for(ll i = ll(a); i >= ll(b); i--)
#define rep(i, b) rng(i, 0, b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int n, m; cin >> n >> m;
    int a[n][m]; rep(i, n) rep(j, m) cin >> a[i][j];
    bool use[m];
    rep(i, m) use[i] = true;
    int ans = n;//INFの気持ち
    rep(k, m) {
        map<int, int> cnt;
        rep(i, n) {
            rep(j, m) {
                if(use[a[i][j] - 1]) {
                    cnt[a[i][j]]++;
                    break;
                }
            }
        }
        int tmp = 0, x = 0;
        for(auto i : cnt) {
            tmp = max(tmp, i.second);
            if(tmp == i.second) x = i.first - 1;
        }
        ans = min(ans, tmp);
        use[x] = false;//一番大きいやつをけしましょか？
    }
    cout << ans << endl;
}
