#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main() {
    ll x, y;
    cin >> x >> y;
    ll ans = inf;
    if(x*y>=0&&y-x>0){
        ans = min(inf, y-x);
    }
    if(x*y>=0&&y-x<0){
        ans = min(abs((-y)+x)+2, ans);
    }
    if(x*y <=0){
        ans = min(abs(x+y)+1, ans);
    }
    cout << ans << endl;
}