#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    int n;
    cin>>n;
    ll ans;
    cin>>ans;
    rep(i,n-1){
        ll a;
        cin>>a;
        ans = ans/__gcd(ans,a)*a;
    }
    cout<<ans<<endl;
    return 0;
}
