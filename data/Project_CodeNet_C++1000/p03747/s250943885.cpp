#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long L,T,X[1<<17],W[1<<17],Y[1<<17];
main()
{
	cin>>n>>L>>T;
	for(int i=0;i<n;i++)cin>>X[i]>>W[i];
	long cnt=0;
	for(int i=1;i<n;i++)
	{
		if(W[i]!=W[0])
		{
			long now=W[0]==1?(2*T-(X[i]-X[0])+L-1)/L:(2*T+(X[i]-X[0])-1)/L;
			cnt+=W[0]==1?now:-now;
			cnt=(cnt+n)%n;
		}
	}
	for(int i=0;i<n;i++)Y[i]=((X[i]+(W[i]==1?T:-T))%L+L)%L;
	long get=Y[0];
	sort(Y,Y+n);
	int id;
	if(W[0]==1)
	{
		for(id=0;Y[id]!=get;id++);
	}
	else
	{
		for(id=n-1;Y[id]!=get;id--);
	}
	for(int i=0;i<n;i++)cout<<Y[(i+id-cnt+n)%n]<<endl;
}