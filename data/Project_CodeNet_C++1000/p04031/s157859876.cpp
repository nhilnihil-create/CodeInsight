#include<bits/stdc++.h>
#define ll long long
const long double pi=acos(-1);
const int N=2e5+10;
using namespace std;
int arr[N];
int main()
{
  	ll n;
  	ll sum1=0,sum=0;
  	cin>>n;
  	for(int i=0;i<n;i++)
  	{
  		cin>>arr[i];
		sum+=arr[i];	
	}
	ll tmp=sum/n;
	for(int i=0;i<n;i++)
	{
		ll k=(arr[i]-tmp);
		sum1+=k*k;
	} 

	tmp++;
	ll sum2=0;
	for(int i=0;i<n;i++)
	{
		ll k=(arr[i]-tmp);
		sum2+=k*k;
	} 
	sum1=min(sum1,sum2);
	cout<<sum1<<"\n";
	return 0;
}