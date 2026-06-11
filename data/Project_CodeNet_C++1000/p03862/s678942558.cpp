#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll>a(n);
    rep(i, 0, n)cin >> a[i];
    ll ans = 0;
    if(a[0]>x){
        ans += (a[0]-x);
        a[0]=x;
    }
    rep(i, 1, n){
        if(a[i]+a[i-1]>=x){
            if(x-a[i-1]>=0){
                ans += (a[i]-x+a[i-1]);
                a[i] = x-a[i-1];
            }else{
                ans += (a[i]-x+a[i-1]);
                a[i] = 0;
            }
        }
    }
    cout << ans << endl;
}