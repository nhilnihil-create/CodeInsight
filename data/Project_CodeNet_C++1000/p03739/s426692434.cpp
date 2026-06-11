#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fcount(ll arr[], ll n, int b, ll val[])
{
	ll c=0;
	ll diff=0;
	for(ll i=0;i<n;i++)
	{	
		if(arr[i]+diff==0)
		{
			if(b==1){
				//arr[i]+=1;
				diff +=1;
				c +=1;
			}
			else{
				//arr[i]-=1;
				diff -=1;
				c+=1;
			}
			//b=(b+1)%2;
		}
		else if(arr[i]+diff>0&&b==0)
		{
			ll temp=diff;
			diff -= (arr[i]+diff+1);
			c += arr[i]+temp+1;
			//b=(b+1)%2;
		}
		else if(arr[i]+diff<0&&b==1)
		{
			ll temp = diff;
			diff +=-(arr[i]+diff)+1;
			c += -(arr[i]+temp)+1;
			//b=(b+1)%2;

		}
	//	else
		b=(b+1)%2;
	//	cout<<diff<<" "<<b<<" "<<c<<"\n";
	}
	//cout<<"\n";
	return c;
}

int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	ll c=0;
	ll diff=0,b=-1;
	ll prefix[n];
	prefix[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		prefix[i]=prefix[i-1]+arr[i];
	}
	//for(int i=0;i<n;i++)
		//cout<<prefix[i]<<" ";
	//cout<<"\n";
	cout<<min(fcount(prefix,n,1,arr),fcount(prefix,n,0,arr))<<"\n";

}