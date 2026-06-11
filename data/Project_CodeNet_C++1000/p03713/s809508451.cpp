#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;

const int N=2e5+100;
const int mod=1e9+7;

ll solve(ll x,ll y,ll z)
{
    if(x<y) swap(x,y);
    if(x<z) swap(x,z);
    if(y<z) swap(y,z);
    return x-z;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    ll h,w;
    cin>>h>>w;
     if(h%3==0 || w%3==0 ) {
        cout<<0<<endl;
        return 0;
     }
    if(h<w) swap(h,w);
    ll ans=1e18;
    ll s2,s3;
    for(int i=1;i<=h;i++){
        ll ww=w;
        ll l=h-i;
        ll s1=i*ww;
        if(l<ww) swap(l,ww);
        if(l*ww%2==0) s2=s3=l*ww/2;
        else {
            s2=(l-1)*ww/2;
            s3=s2+min(l,ww);
        }
      // cout<<s1<<" "<<s2<<" "<<s3<<endl;
       ans=min(ans,solve(s1,s2,s3));
    }
    swap(h,w);
    for(int i=1;i<=h;i++){
        ll ww=w;
        ll l=h-i;
        ll s1=i*ww;
        if(l<ww) swap(l,ww);
        if(l*ww%2==0) s2=s3=l*ww/2;
        else {
            s2=(l-1)*ww/2;
            s3=s2+min(l,ww);
        }
      // cout<<s1<<" "<<s2<<" "<<s3<<endl;
       ans=min(ans,solve(s1,s2,s3));
    }
    cout<<ans<<endl;
    return 0;
}

