#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

signed main() {
    int n,c,k;
    cin >> n>> c>>k;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    sort(t.begin(),t.end());
    int en = t[0]+k;
    int id = 1;
    int cnt = 1;
    int ans = 1;
    while(id<n) {
        if(en>=t[id]) {
            cnt++;
            if(cnt>=c) {
                cnt=0;
                ans++;
                if(id+1<n) en = t[id+1]+k;
            }
        }else {
            cnt=1;
            ans++;
            en = t[id]+k;
        }
        id++;
    }
    cout << ans << endl;

    return 0;
}

