#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    vector<ll> b(n,0);
    rep(i,n)cin >> a[i] >> b[i];
    ll res = 0;
    per(i,n-1){
        a[i] += res;
        if(b[i] == 1)continue;
        res +=  b[i]*( (a[i]+b[i]-1)/b[i] ) - a[i];
    }
    cout << res << endl;
    return 0;
}