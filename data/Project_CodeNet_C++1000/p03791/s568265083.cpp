#include<iostream>
using namespace std;
int N,X[1<<17];
long ans=1,mod=1e9+7;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>X[i];
	}
	X[0]=1;
	int t=0;
	for(int i=1;i<N;i++)
	{
		if(X[i-1]+2<=X[i])X[i]=X[i-1]+2;
		ans=ans*(i+1-(t+1)/2)%mod;
		if(X[i-1]+1==X[i])t++;
	}
	cout<<ans<<endl;
}
