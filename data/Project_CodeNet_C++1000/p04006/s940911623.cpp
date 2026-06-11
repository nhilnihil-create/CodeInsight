#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<time.h>
#include<sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF=0x3f3f3f3f3f3f;
//const ll mod=;

//map<string,ll> m;
//map<ll,ll> m;

//set<ll> s;

//vector<ll> v;

//ios_base::sync_with_stdio(0); cin.tie(0);

//scanf("%lld",&t);
//scanf("%lld%lld",&,&);

//cout<<  <<"\n";
//cout<<fixed<<setprecision()<<;

//ll n,m,t,a,x,ans,res;
ll n,x,a[2010],b[2010];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];b[i]=a[i];
	}
	ll minn=INF;
	for(int k=0;k<n;k++)
	{
		ll sum=k*x;
		for(int j=0;j<n;j++)
		{
			b[(j+k)%n]=min(b[(j+k)%n],a[j]);
			sum+=b[(j+k)%n];
		}
		minn=min(sum,minn);
	}
	cout<<minn<<endl;
	return 0;
}





//ll powmod(ll a,ll b)     //快速幂 
//{
//	ll tmp=a;
//	ll ans=1;
//	while(b)
//	{
//		if(b&1)ans=ans*tmp%mod;
//		tmp=tmp*tmp%mod;
//		b>>=1;
//	}
//	return ans%mod;
//}


//bool is_prime(ll a)     //判断素数 
//{
//	if(a==2)return 1;
//	else if(a==1||a%2==0)return 0;
//	else
//	{
//		for(ll i=3;i*i<=a;++i)
//		{
//			if(a%i==0)return 0;
//		}
//	}
//	return 1;
//}







