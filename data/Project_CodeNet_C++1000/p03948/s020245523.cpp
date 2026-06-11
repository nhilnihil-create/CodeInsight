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
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    ll N, T; cin >> N >> T;
    ll A[N]; rep(i, N) cin >> A[i];
    ll minv[N + 1], maxv[N + 1];
    minv[0] = INF, maxv[N] = 0;
    rep(i, N) {
        minv[i + 1] = min(minv[i], A[i]);
        maxv[N - 1 - i] = max(maxv[N - i], A[N - 1 - i]);
    }
    ll ans = 0;
    rep(i, N) {
        ans = max(maxv[i] - minv[i], ans);
    }

    ll cnt = 0;
    bool flg = false;
    rep(i, N) {
        if(flg && ans == maxv[i] - minv[i]) continue;
        flg = false;
        if(ans == maxv[i] - minv[i])
            ++cnt, flg = true;
    }
    cout << cnt << endl;
}
