#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // 元の数字のままで正負が逆転するなら、そのまま
    // 逆転しないなら、和が1か-1になるまで操作する
    // 正負正負正負.. と負正負正負.. の2パターン
    ll ans = LLONG_MAX;
    rep(i, 2) { //i = 0:正負, i=1:負正
        vector<int> s(n);
        ll tmp = 0;
        rep(j, n) {
            if (j==0) s[0]=a[0];
            else s[j] = s[j-1]+a[j];
            if ((i+j)%2==0) { // 正であってほしい
                if(s[j]>0) continue;
                else {
                    tmp += 1-(s[j]);
                    s[j] = 1;
                }
            } else {
                if (s[j]<0) continue;
                else {
                    tmp += s[j]-(-1);
                    s[j] = -1;
                }
            }
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
}