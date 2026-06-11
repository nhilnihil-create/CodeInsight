#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
long long cur;
int w;
long long p[18],po[18];
int bs(int x)
{
	int l=-1,r=10;
	if(x==1)l=0;
	while(l+1<r)
	{
		int m=(l+r)/2;
		printf("? %lld\n",(cur*10LL+m)*po[13-x]+p[13-x]);
		char op;
		cin>>op;
		if(op=='N')l=m;else r=m;
	}
	return l;
}
int main()
{
	po[0]=1LL;
	for(int i=1;i<=17;i++)p[i]=p[i-1]*10LL+9,po[i]=po[i-1]*10LL;
	w=1;
	printf("? %lld\n",po[10]);
	char op;
	cin>>op;
	if(op=='Y')
	{
		int s=0;
		do
		{
			printf("? %lld\n",2*po[s]);
			cin>>op;
			s++;
		}
		while(op=='N');
		s--;
		printf("! %lld",po[s]);
		return 0;
	}
	while(1)
	{
		if(w>10)
		{
			long long t=1LL;
			int s=1;
			do
			{
				printf("? %lld\n",po[s]);
				cin>>op;
				s++;
			}
			while(op=='Y');
			s--;
			printf("! %lld",cur/po[10-s]);
			return 0;
		}
		int k=bs(w);
		cur=cur*10LL+k+1;
		w++;
	}
	return 0;
}