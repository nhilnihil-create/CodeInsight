#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
const ll mod=1e9+7;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q,h,s,d,n;
    cin>>q>>h>>s>>d>>n;
    n*=4;
    if(2*q<h)
        h=2*q;
    if(2*h<s)
        s=2*h;
    if(2*s<d)
        d=2*s;
    ll a[9];
    a[1]=q;a[2]=h;a[4]=s;a[8]=d;
    ll min=8,ans=0;
    while(n!=0){
        if(n<min)
            min/=2;
        n-=min;
        ans+=a[min];
    }
    cout<<ans;
    /*ll dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1e10;
    dp[1]=q;
    for(ll i=2;i<=n;i++){
        ll a=0,b=0;
        a=min(dp[i-1]+q,dp[i-2]+h);
        if(i>=8) b=min(dp[i-4]+s,dp[i-8]+d);
        else if(i>=4) b=dp[i-4]+s;
        dp[i]=min(a,b);
    }
    cout<<dp[n];*/

    return 0;
}
