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
    ll i,o,t,j,l,s,z;cin>>i>>o>>t>>j>>l>>s>>z;
    ll ans1 = i/2*2+o+j/2*2+l/2*2;
    if(i>0&&j>0&&l>0){
        ll i2=i-1, j2=j-1, l2=l-1;
        ll ans2 = i2/2*2+o+j2/2*2+l2/2*2+3;
        ans1 = max(ans1,ans2);
    }

    cout<<ans1<<endl;
    return 0;
}