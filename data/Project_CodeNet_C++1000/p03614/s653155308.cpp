#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, char *argv[])
{
	int n,i,f,g=1,sum=0;
	int a[100000];
	int b[100000];
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		if(a[i]==i+1)
		{
			int t;
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			b[i]++;
		}
	}
	if(a[n-1]==n)
	{
			int t;
			t=a[n-2];
			a[n-2]=a[n-1];
			a[n-1]=t;
			b[n-1]++;
	}
	for(i=n-2;i>=0;i--)
	{
		if(a[i]==i+1)
		{
			int t;
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			b[i]--;
		}
	}
	for(i=0;i<n;i++)
	{
		if(b[i]<0)b[i]=-b[i];
		sum=sum+b[i];
	}
	printf("%d\n",sum);
	return 0;
}