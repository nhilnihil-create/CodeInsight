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
		printf("? %lld\n",(cur*10LL+m)*po[11-x]+p[11-x]);
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
	while(1)
	{
		if(w>10)
		{
			long long t=cur;
			long long cj=1LL;
			while(t%10==0)
			{
				t/=10LL;
				cj*=10LL;
			}
			t/=10LL;
			cj*=10LL;
			char op;
			do
			{
				t=t*10LL+9;
				cj/=10LL;
				printf("? %lld\n",t);
				cin>>op;
			}
			while(op=='N');
			long long res=cur/cj;
			/*if(res%10LL==9)
			{
				char op;
				printf("? %lld\n",(res/10LL)*100LL);
				cin>>op;
				if(op=='Y')res*=10LL;
			} */
			printf("! %lld",res);
			return 0;
		}
		int k=bs(w);
		cur=cur*10LL+k+1;
		w++;
	}
	return 0;
}