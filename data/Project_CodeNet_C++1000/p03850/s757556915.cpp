#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long sum,a,n,ans,L;
char op;
vector<long>A;
main()
{
	cin>>n;
	cin>>a;
	A.push_back(a);
	sum+=a;
	for(int i=1;i<n;i++)
	{
		cin>>op>>a;
		if(op=='-')
		{
			A.push_back(-a);
			A.push_back(0);
			sum-=a;
		}
		else
		{
			A.back()+=a;
			sum+=a;
		}
	}
	ans=sum;
	for(int i=A.size()-2;i>0;i-=2)
	{
		ans=max(ans,sum-A[i+1]*2+L);
		sum=sum-A[i]-A[i+1];
		L+=-A[i]+A[i+1];
	}
	cout<<ans<<endl;
}
