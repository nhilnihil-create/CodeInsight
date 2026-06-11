#include <bits/stdc++.h>
#define N 210
#define ll long long
using namespace std;
int n,f[N],a[N];
ll s;

int main(){
	scanf("%lld",&s);
	for (n=0;s;)
		if (!(s&1))
			s--,a[++n]=0;
		else
			s>>=1,a[++n]=1;
	int h=1,r=n;
	for (int i=1;i<=n;i++)
		if (a[i])
			f[r--]=n-i+1;
		else
			f[h++]=n-i+1;
	printf("%d\n",n*2);
	for (int i=1;i<=n;i++)
		printf("%d ",f[i]);
	for (int i=1;i<n;i++)
		printf("%d ",i);
	printf("%d\n",n);
	return 0;
}