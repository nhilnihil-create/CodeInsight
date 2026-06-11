#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;


ll res(ll h,ll w) {
    ll ans=0;
    vector<ll> s(3);
    if (h%3==1) {
        s[0]=(h/3)*w;
        s[1]=(h-h/3)*(w/2);
        s[2]=(h-h/3)*(w-w/2);
        sort(s.begin(),s.end());
        ans=(s[2]-s[0]<w)?(s[2]-s[0]):w;
    } else if (h%3==2) {
        s[0]=(h/3+1)*w;
        s[1]=(h-h/3-1)*(w/2);
        s[2]=(h-h/3-1)*(w-w/2);
        sort(s.begin(),s.end());
        ans=(s[2]-s[0]<w)?(s[2]-s[0]):w;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); 

    ll h,w;
    cin >> h >> w;
    ll ans1=res(h,w);
    ll ans2=res(w,h);
    ll ans=(ans1<ans2)?ans1:ans2;
    cout << ans << endl;
    return 0;
}