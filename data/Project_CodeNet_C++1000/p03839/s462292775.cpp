#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e5+10;
const ll mod =   1e9+7;
ll n,k, pre[N],suff[N],arr[N],presum[N];
int main()
{  fast
cin>>n>>k;
for(int i=1;i<=n;i++)
{

cin>>arr[i];
presum[i]=presum[i-1]+arr[i];//cout<<presum[i]<<endl;
}
ll ans=0;
for(int i=1;i<=n;i++)
{
	pre[i]=max(pre[i-1],pre[i-1]+arr[i]);
	suff[n-i+1]=max(suff[n-i+2],suff[n-i+2]+arr[n-i+1]);
}
for(int i=k;i<=n;i++)
{

ans=max(ans,pre[i-k]+suff[i+1]+max(0ll,presum[i]-presum[i-k]));
//cout<<pre[i-k]<<" "<<suff[i+1]<<" "<<presum[i]<<" "<<presum[i-k]<<endl;
}
cout<<ans;
}