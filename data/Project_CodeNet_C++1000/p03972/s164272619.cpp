#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll h,w,ans=0,num;
    cin>>w>>h;
    ll p[w],q[h];
    for(int i=0;i<w;i++){
        cin>>p[i];
        ans+=p[i];
    }
    for(int i=0;i<h;i++){
        cin>>q[i];
        ans+=q[i];
    }
    sort(p,p+w);
    sort(q,q+h);
    ll ps[w+1],qs[h+1];
    ps[0]=qs[0]=0;
    for(int i=1;i<=w;i++){
        ps[i]=ps[i-1]+p[i-1];
    }
    for(int i=0;i<h;i++){
        num=(lower_bound(p,p+w,q[i])-p);
        ans+=(w-num)*q[i]+ps[num];
    }
    cout << ans<<endl;
    return 0;
}
