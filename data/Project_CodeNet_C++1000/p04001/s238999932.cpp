#include<bits/stdc++.h>
using namespace std;
char s[15];
long long cof[15],n,datat[15],pow_10[10],cnt,cou=0;
void gen(long long lv)
{
	if(lv==n-1)
	{
		datat[n-1]=1;
		/*for(int i=0;i<n-1;i++)
		{
			printf("%lld ",data[i]);
		}
		printf("\n");*/
		cnt=0;
		for(int i=n-1;i>=0;i--)
		{
			if(datat[i]==1)
			{
				cnt=0;
			}else
			{
				++cnt;
			}
			cof[i]=cnt;
		}
		/*for(int i=0;i<n;i++)
		{
			printf("%lld ",cof[i]);
		}
		printf("\n");*/
		for(int i=0;i<n;i++)
		{
			cou+=(pow_10[cof[i]]*(s[i]-48));
		}
		return;
	}
	for(int i=0;i<=1;i++)
	{
		datat[lv]=i;
		gen(lv+1);
	}
}
int main()
{
	pow_10[0]=1;
	for(int i=1;i<=10;i++)
	{
		pow_10[i]=pow_10[i-1]*10;
	}
	scanf("%s",s);
	n=strlen(s);
	gen(0);
	printf("%lld\n",cou);
}