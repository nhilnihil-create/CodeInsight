#include <bits/stdc++.h>
#define N 100010
#define INF 100000010
using namespace std;
int main(){
	long long n,k,i,j,l,a[N],qdh[N],pos[N],unpos[N],maxs=-INF,mins=INF,tem,tem2;
	cin>>n>>k;
	qdh[0]=0;
	a[0]=0;
	pos[0]=0;
	unpos[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>0)
		{
			pos[i]=pos[i-1]+a[i];
			unpos[i]=unpos[i-1];
		}
		else
		{
			unpos[i]=unpos[i-1]+a[i];
			pos[i]=pos[i-1];
		}
		qdh[i]=qdh[i-1]+a[i];
	}
	for(i=0;i+k<=n;i++)
	{
		tem=qdh[i+k]-qdh[i];
		tem2=pos[i+k]-pos[i-1];
		maxs=max(maxs,tem+pos[n]-tem2);
		tem2=unpos[i+k]-unpos[i-1];
		mins=min(mins,tem+unpos[n]-tem2);
	}
	cout<<max(maxs,qdh[n]-mins)<<endl;
	return 0;
}
