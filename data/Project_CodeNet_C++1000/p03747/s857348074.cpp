#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#define N 200005
using namespace std;
int Rank,n,l,t;
int x[N],w[N],e[N];
int main()
{
	scanf("%d%d%d",&n,&l,&t);
	Rank=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&w[i]);
		e[i]=x[i]+((w[i]==1)?1:-1)*t;
		e[i]%=l;
		e[i]=(e[i]+l)%l;
		if (w[i]==1)
			Rank+=(x[i]+t)/l; else
			Rank-=(l-x[i]-1+t)/l;
		Rank=(Rank%n+n)%n;
	}
	sort(e,e+n);
	for (int i=Rank;i<n;i++)
		printf("%d\n",e[i]);
	for (int i=0;i<Rank;i++)
		printf("%d\n",e[i]);
	return 0;
}