#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=LLONG_MAX;
const int inf=INT_MAX;
const int nmax=1e5+5;
const int mod=1e9+7;
using namespace std;
int n,m,x,a[nmax],nr[nmax],tot[nmax],i,ans;
int main()
{
    //freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>x,nr[x]++,a[x%m]++;
    for(i=1;i<=100000;i++)tot[i%m]+=nr[i]/2;
    ans=a[0]/2;
    if(m%2==0)ans+=a[m/2]/2;
    for(i=1;i<=(m-1)/2;i++)
	{
	   if(a[i]<a[m-i])ans+=min((a[m-i]-a[i])/2,tot[m-i])+a[i];
	   else ans+=min((a[i]-a[m-i])/2,tot[i])+a[m-i];
	}
	cout<<ans<<endl;
	return 0;
}