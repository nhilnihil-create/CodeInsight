#include<iostream>
#include<cstdio>
using namespace std;
int n,a[301010],b[301010];
bool check(int x)
{
	for(int i=1;i<=n*2+1;i++)
	b[i]=(a[i]>x);
	b[0]=b[1];
	for(int i=n,j=n;i;i--,j++)
	if(b[i]==b[i-1]) return b[i];
	else if(b[j]==b[j+1]) return b[j];
}
	
int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n*2-1;i++)
	scanf("%d",&a[i]);
	int l=1,r=n*2-1,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(!check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}