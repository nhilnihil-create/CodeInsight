#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k;
ll a[100005];
ll b[100005];
ll c[100005];
ll d[100005];
ll sum;
ll m=1000000000000000000,M=-1000000000000000000;
int main(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
        if(a[i]>0) sum+=a[i];
        if(a[i]<0) a[i]=0;
        if(b[i]>0) b[i]=0;
        c[i+1]=c[i]+a[i];
        d[i+1]=d[i]+b[i];
    }
    for(int i=0;i<=n-k;i++){
        m=min(m,c[i+k]-c[i]);
        M=max(M,d[i+k]-d[i]);
        //cout<<m<<" "<<M<<endl;
    }
    ll ans=max(sum+M,sum-m);
    if(ans<0) ans=0;
    cout<<ans<<endl;


}

