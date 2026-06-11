#include<iostream>
#include<cstdio>
#include<vector>
#include<limits>
#include<cmath>
using namespace std;
long long a[3000],minn[3000],n,x,sum=0,t=0,sum1;
int main()
{
	cin>>n>>x;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		minn[i]=a[i];
		sum+=a[i];
	}
	for(int i=1;i<n;++i)
	{
		sum1=0;
		for(int j=0;j<n;++j)
		{
			minn[j]=min(minn[j],a[(i+j)%n]);
			sum1+=minn[j];
		}
		sum=min(sum,sum1+x*i);
	}
	cout<<sum;
	
	

}