#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define debug(x) cout<<x<<"\n";
#define Max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const int N=1e5+10;
const ll inf=0x3f3f3f3f3f3f;
using namespace std;
ll arr[N];
int main()
{	
	ll x,n,cnt=0;
	while(cin>>n>>x)
	{
		for(int i=0;i<n;i++)
		cin>>arr[i];
		ll ans=0;
		if(arr[0]>x)
		{
			ans+=((arr[0]-x));
			arr[0]=x;	
		}
		for(int i=0;i<n;i++)
		{
			if(arr[i]+arr[i+1]>x)
			{
				ll temp=arr[i]+arr[i+1]-x;
				ans+=temp;
				if(arr[i+1]>=temp)
				arr[i+1]-=temp;
				else
				{
					arr[i+1]=0;
					arr[i]-=(arr[i]-x);
				}
			}
		}
		//debug(arr[0]);debug(arr[1]);
		cout<<ans<<"\n";
	}
	return 0;
} 