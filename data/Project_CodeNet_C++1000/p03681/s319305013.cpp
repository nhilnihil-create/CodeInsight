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

ll factorial(int a){
    ll num = 1;
    rep(i, 1, a+1){
        num *= i;
        num %= mod;
    }
    return num;
}
int main(){
    int n, m;
    cin >> n >> m;
    if(n == m){
        ll ans = 2*(factorial(n)*factorial(m)%mod);
        ans %= mod;
        cout << ans << endl;
        return 0;
    }
    int p = max(n, m);
    int q = min(n, m);
    if(p-q>1){
        cout << 0 << endl;
        return 0;
    }else{
        ll ans = (factorial(n)*factorial(m)%mod);
        cout << ans << endl;
        return 0;
    }
}