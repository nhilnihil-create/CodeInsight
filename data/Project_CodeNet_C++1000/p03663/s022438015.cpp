#include<bits/stdc++.h>
using namespace std;
int qry(long long x)
{
	char ch[2];
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",ch);
	if(ch[0]=='Y') return 1;
	return 0;
}
int main()
{
	int l=1;
	long long pw=1;
	for(;l<=11;l++,pw*=10)if(!qry(pw))break;
	if(l==12)
	{
		long long mx=9,res=1;
		for(;;mx=mx*10+9,res*=10)
		{
			if(qry(mx))
			{
				printf("! %I64d\n",res);
				fflush(stdout);
				return 0;
			}
		}
	}
	else l--;
	long long lf=1,rg=1,md,res;
	for(int i=1;i<l;i++)lf*=10;
	rg=lf*10-1;
	while(lf<=rg)
	{
		md=(lf+rg)/2;
		if(qry(md*10ll))
		{
			res=md;
			rg=md-1;
		}
		else
			lf=md+1;
	}
	printf("! %I64d\n",res);
	fflush(stdout);
	return 0;
}