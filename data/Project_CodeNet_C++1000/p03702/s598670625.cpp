#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005];
int main()
{
	long long n,A,B;
	cin>>n>>A>>B;
	long long m=A-B;
	for(int i=1;i<=n;++i) cin>>a[i];
	long long l=1,r=1000000000;
	while(l<r)
	{
		long long mid=(l+r)/2;
		long long q=mid;
		for(int i=1;i<=n;++i)
		{
			b[i]=a[i];
			b[i]-=mid*B;
			if(b[i]>0)
			{
				long long a1=b[i]/m;
				long long a2=b[i]%m;
				if(a2!=0) a2=1;
				q-=a1+a2;
			}
		}
		if(q<0) l=mid+1;
		else r=mid;
	 } 
	cout<<l<<endl;
	return 0;
}