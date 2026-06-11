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
typedef long long ll;
using namespace std;

const int N = 111111;
int a[N];
int n;

pair<vector<int>, vector<int> > split() {
    vector<int> ev, ov;
    rep(i, 1, n) {
        if(i & 1) {
            ov.pb(a[i]);
        } else {
            ev.pb(a[i]);
        }
    }
    return {ov, ev};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
    }
    pair<vector<int>, vector<int> > v = split();
    sort(a + 1, a + n + 1);
    unordered_set<int> so, se;
    rep(i, 1, n) {
        if(i & 1) {
            so.insert(a[i]);
        } else {
            se.insert(a[i]);
        }
    }
    int ans = 0;
    rep(i, 0, sz(v.fi) - 1) {
        ans += so.find(v.fi[i]) == so.end();
    }
    cout << ans << endl;
    return 0;
}
