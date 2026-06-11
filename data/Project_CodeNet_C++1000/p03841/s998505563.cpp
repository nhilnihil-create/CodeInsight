#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), ans(n * n, -1);
    vector<P> d; 
    rep(i, 0, n){
        cin >> a[i]; a[i]--;
        ans[a[i]] = i + 1;
        d.push_back(P(a[i], i + 1));
    }
    sort(all(d));
    bool f = true;
    rep(i, 0, n){
        int cnt = d[i].second - 1;
        rep(j, 0, d[i].first){
            if(cnt == 0) break;            
            if(ans[j] == -1){
                cnt--;
                ans[j] = d[i].second;
            }
        }
        if(cnt != 0) f = false;
    }
    reverse(all(d));
    rep(i, 0, n){
        int cnt = n - d[i].second;
        repb(j, n * n - 1, d[i].first + 1){
            if(cnt == 0) break;            
            if(ans[j] == -1){
                cnt--;
                ans[j] = d[i].second;
            }
        }
        if(cnt != 0) f = false;
    }
    if(!f) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        for(int ii = 0; ii < ans.size(); ii++){
            if(ii) cout << ' ';
            cout << ans[ii];
        }
        cout << endl;
    }
}