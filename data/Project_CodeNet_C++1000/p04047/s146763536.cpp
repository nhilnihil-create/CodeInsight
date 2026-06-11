#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;cin>>n;
    vector<ll> l(2*n);rep(i,2*n)cin>>l[i];
    sort(ALL(l));
    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += min(l[2*i+1],l[2*i]);
    }
    cout<<ans<<endl;
    return 0;
}