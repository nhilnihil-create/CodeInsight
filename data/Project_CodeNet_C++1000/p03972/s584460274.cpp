#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rng(a) a.begin(), a.end()
#define ina(n,a) cin >> n; for(int i = 1; i <= n; i++) cin >> a[i]
#define sz(x) (int)(x).size()
#define se second
#define fi first
#define prev            coyhhhhhhyoc    
#define next          sdNNNmNNNNNNNmds  
#define y0           hNNNNy_yNNNNNN_sNh
#define y1          mNNNNNdtdNNNNNNtsNNm
#define yn          mNNNNNNNNy___smNNNms
#define tm            oooooosyysooooot 
#define read               tyhyt        
#define rank              ytmNmo         
#define index              yyy
#define pb push_back
#define pcnt __builtin_popcountll
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#define rall(x,a) for(auto x : a)
#define MOD 1000000007
#define endl "\n"
#define int long long
typedef long long ll;
using namespace std;

const int N = 111111;
int p[N], q[N];
vector<pair<int, int> > v;
int w, h;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w >> h;
    rep(i, 1, w) {
        cin >> p[i];
    }
    rep(i, 1, h) {
        cin >> q[i];
    }
    rep(i, 1, w) {
        v.pb({p[i], 0});
    }
    rep(i, 1, h) {
        v.pb({q[i], 1});
    }
    sort(rng(v));
    int r = 0, c = 0, ans = 0;
    rall(pa, v) {
        bool row = pa.se;
        int x = pa.fi;
        if(row) {
            ans += (w - r + 1) * x;
            c++;
        } else {
            ans += (h - c + 1) * x;
            r++;
        }
    }
    cout << ans << endl;
    return 0;
}
