#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cassert>
#define llong long long
using namespace std;

const int N = 1e5;
int permu[N+3];
int tmp[N+3];
int aux[N+3];
llong a[N+3],d[N+3];
int n,m; llong p;

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]),d[i-1] = a[i]-a[i-1];
	for(int i=1; i<n; i++) permu[i] = i;
	scanf("%d%lld",&m,&p);
	for(int i=1; i<=m; i++)
	{
		int x; scanf("%d",&x);
		swap(permu[x-1],permu[x]);
	}
	for(int i=1; i<n; i++) tmp[i] = permu[i],permu[i] = i;
	for(int i=0; p; i++)
	{
		if(p&(1ll<<i))
		{
			for(int j=1; j<n; j++) aux[j] = permu[tmp[j]];
			for(int j=1; j<n; j++) permu[j] = aux[j];
			p-=(1ll<<i);
		}
		for(int j=1; j<n; j++) aux[j] = tmp[tmp[j]];
		for(int j=1; j<n; j++) tmp[j] = aux[j];
	}
	for(int i=1; i<n; i++) a[i+1] = a[i]+d[permu[i]];
	for(int i=1; i<=n; i++) printf("%lld.0\n",a[i]);
	return 0;
}