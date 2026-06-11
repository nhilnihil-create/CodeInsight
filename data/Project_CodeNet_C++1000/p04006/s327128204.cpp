#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define INF LONG_LONG_MAX
#define MOD 1000000007
#define yn(f) cout << (f ? "Yes" : "No") << endl;
#define YN(f) cout << (f ? "YES" : "NO") << endl;

int n,x,a[2000],ans=INF;

signed main() {
    cin >> n >> x;
    rep(i,n) cin >> a[i];
    rep(i,n+1) {
        int tmpans=i*x;
        deque<pair<int,int>> d;
        for(int j=n-i;j<n;++j) {
            while(d.size() && d.back().fi > a[j]) d.pop_back();
            d.push_back(mp(a[j],j-n));
        }
        rep(j,n) {
            while(d.size() && j - d.front().se > i) d.pop_front();
            while(d.size() && d.back().fi > a[j]) d.pop_back();
            d.push_back(mp(a[j], j));
            tmpans += d.front().fi;
        }
        ans = min(ans, tmpans);
    }
    cout << ans << endl;
}


