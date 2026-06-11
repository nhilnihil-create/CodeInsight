#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,L,R,a[55],ans1,ans2,cnt1,cnt2;
bool cmp(ll a,ll b){return a>b;}
ll C[55][55];
int main()
{
    C[0][0]=1;
    for(ll i=1;i<=50;i++)
	{
        C[i][0]=1;
        for(ll j=1;j<=i;j++)
        	C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    cin>>n>>L>>R;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n,cmp); 
    for(ll i=1;i<=L;i++) ans1+=a[i];
    for(ll i=1;i<=n;i++) if(a[i]==a[L]) cnt1++;
    for(ll i=1;i<=L;i++) if(a[i]==a[L]) cnt2++;
    if(a[1]==a[L])
        for(ll i=L;i<=R;i++) 
			ans2+=C[cnt1][i];
    else 
		ans2=C[cnt1][cnt2];
    printf("%lf\n%lld",(double)ans1/L,ans2);
    return 0;
}