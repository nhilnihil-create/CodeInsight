#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for( i=a;i<b;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const ll MOD=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ll t=1,a=1;
    rep(i,n) {
        ll tt,aa;
        cin >> tt >> aa;
        t+=(tt-(t%tt))%tt;
        a+=(aa-(a%aa))%aa;
        ll r=(t/tt>a/aa)?(t/tt):(a/aa);
        t=r*tt;
        a=r*aa;
    }
    cout << t+a << endl;
    return 0;
}