#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n;cin >> n;
    ll sum = 0;
    vi a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,n){
        ans += a[i]/2;
        if(i+1<n && (a[i]&1) && a[i+1]>0) ++ans,--a[i+1];
    }
    cout << ans << endl;
}