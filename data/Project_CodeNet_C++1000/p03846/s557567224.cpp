#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#define lowbit(x) ((x)&(-x))
#define sc scanf
#define debug1(x) cout<<x<<" "
#define debug2(x) cout<<x<<"\n"
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
typedef long long ll;
const ll inf=1e18;
const int N=1e5+10;
ll mod=1e9+7;
using namespace std;
int gcd(int a,int  b){return b==0?a:gcd(b,a%b);}
int arr[N],brr[N];
ll quick_pow(ll a,ll b,ll m)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
		{
			ret*=a;
			ret%=m;
		}
		a*=a;
		a%=m;
		b>>=1;
	}
	return ret;
}
int main()
{
	int n;
	while(cin>>n)
	{
		memset(brr,0,sizeof(brr));
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
			brr[arr[i]]++;
		}
		long long sum=0,i;
		if(n%2==0)i=1;
		else i=0; 
		for(;i<n;i+=2)
		{
			if(brr[i]>2||brr[0]>1)
			{
				break;
			}
			sum+=brr[i];
		}
		if((sum==n))
		{
			ll ans=quick_pow(2,n/2,mod);
			cout<<ans<<"\n";
		}	
		else
		cout<<"0"<<"\n";
	}	
	return 0;
}