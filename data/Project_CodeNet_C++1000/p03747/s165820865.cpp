#include<bits/stdc++.h>
using namespace std;
long long n,l,t,flag,x[23333333];
int main()
{
	cin>>n>>l>>t;
	int emm=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>flag;
		if(flag==2) flag=-1;
		emm+=(x[i]+flag*t)/l;
		x[i]=(x[i]+flag*t)%l;
		if(x[i]<0) x[i]+=l,emm--;
	}
	emm=(emm%n+n)%n;
	sort(x+1,x+n+1);
	for(int i=emm+1;i<=n;i++) cout<<x[i]<<endl;
	for(int i=1;i<=emm;i++) cout<<x[i]<<endl;
}