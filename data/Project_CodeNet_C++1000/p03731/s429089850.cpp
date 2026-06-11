#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

signed main(){
    int n, T;
    cin >> n >> T;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    
    int ans = T;
    rep(i,n-1){
        ans += min(t[i+1] - t[i], T);
    }
    
    cout << ans << endl;
}