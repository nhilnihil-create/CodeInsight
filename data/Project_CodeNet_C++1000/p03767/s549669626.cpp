#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using p = pair<ll,ll>;
using vv = vector<vector<ll>>;
template <class _t> inline bool chmax (_t& a,_t b){if(a<b){a=b;return true;}return false;}
template <class _t> inline bool chmin (_t& a,_t b){if(a>b){a=b;return true;}return false;}

const long long inf = 1ll << 60;
const long long mod = 1000000007;

int main(void){
    int n;cin >> n;
    vector<int> a(3*n);
    rep(i,3*n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    ll ans =0;
    for(int i=0;i<2*n;i++){
	if(i%2==1)ans += a[i]; 
    }
    cout << ans << endl;
    return 0;
}
