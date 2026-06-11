#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;


int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans1=0,s1=0;    
    rep(i,n) {
        s1+=a[i];
        if (i%2==0) {
            if (s1<=0) {
                ans1+=-s1+1;
                s1=1;
            }
        } else {
            if (s1>=0) {
                ans1+=s1+1;
                s1=-1;
            }
        }
    }
    ll ans2=0,s2=0;    
    rep(i,n) {
        s2+=a[i];
        if (i%2==1) {
            if (s2<=0) {
                ans2+=-s2+1;
                s2=1;
            }
        } else {
            if (s2>=0) {
                ans2+=s2+1;
                s2=-1;
            }
        }
    }
    ll ans=(ans1<ans2)?ans1:ans2;
    cout << ans << endl;

    return 0;
}