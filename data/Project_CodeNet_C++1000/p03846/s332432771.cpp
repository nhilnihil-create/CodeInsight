#include<bits/stdc++.h>
#define ll long long
#define  mod 1000000007
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int ct[n]={0};
	int f=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ct[a[i]]++;
	}
	if(n%2==0)
	{
		for(int i=0;i<n;i++)
		{
			if(i!=0&&i%2==1&&ct[i]!=2){f=0;break;}
			if(i==0&&ct[i]>0){f=0;break;}
		}
	}
	else if(n%2==1)
	{
		for(int i=0;i<n;i++)
		{
			if(i==0&&ct[i]>1){f=0;break;}
			if(i!=0&&i%2==0&&ct[i]!=2){f=0;break;}
		}
	}
	if(f==0)cout<<0;
	else{
		ll res=1LL;
		ll b=n/2;
		ll a=2LL;
		while(b>0)
		{
			if(b&1)res=(res*a)%mod;
			a=(a*a)%mod;
			b>>=1;
		}
		cout<<res;
	}
}