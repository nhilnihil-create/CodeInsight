#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);

    ll n,u;
    cin >> n >> u;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    ll ol=0;
    rep(i,n-1) {
        ol+=(t[i+1]-t[i]<u)?(u-(t[i+1]-t[i])):0;
    }
    ll ans=n*u-ol;
    cout << ans << endl;

    return 0;   
}
