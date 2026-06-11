#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
ll n,k,a[N],num[N],mi=0x3f3f3f3f3f3f3f;
int main()
{
	cin>>n>>k;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		num[i]=a[i];
		sum+=a[i]; 
	}
	mi=min(mi,sum);
	for(int i=1;i<n;i++)
	{
		sum=0;
		for(int j=0;j<n;j++)
		{
			num[j]=min(num[j],a[(j+n-i)%n]);
			sum+=num[j];
		}
		mi=min(mi,sum+i*k);
	}
	cout<<mi<<endl;
}