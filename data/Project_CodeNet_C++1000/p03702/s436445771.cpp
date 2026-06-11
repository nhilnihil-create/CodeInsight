//Atcoder regular contest 075 Problem D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll n,a,b;
ll arr[100005];
bool chk(ll mid)
{
	ll cnt=0;
	ll x=b*mid;
	ll y=a-b;
	for(ll i=0;i<n;i++)
	{
		if(arr[i]-x>0){
			if((arr[i]-x)%y==0)
				cnt+=((arr[i]-x)/y);
			else
				cnt+=((arr[i]-x)/y)+1;
		}
	}
	//cout<<cnt<<" "<<mid<<" "<<x<<" "<<y<<endl;
	if(cnt>mid)
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	cin>>n>>a>>b;
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	ll low=0,high=1e9;
	ll ans=1e10;
	while(low<=high)
	{
		ll mid=(low+high)/2;
		if(chk(mid))
		{
			ans=min(ans,mid);
			high=mid-1;
		}
		else
			low=mid+1;
	}
	cout<<ans<<endl;
}	