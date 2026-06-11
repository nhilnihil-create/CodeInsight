#include<bits/stdc++.h>
using namespace std;
char s[5];
void query(long long x){printf("? %lld\n",x);fflush(stdout);scanf("%s",s);}
int main()
{
	long long x=1e9;
	query(x);
	if(s[0]=='Y')
	{
		for(int i=9;i>=1;i--)
		{
			query(x-1);
			if(s[0]=='N')break;
			x/=10;
		}
		printf("! %d\n",x);
		return 0;
	}
	while(s[0]=='N')query(x/=10);
	long long l=x+1,r=x*10-1,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		query(mid*10);
		if(s[0]=='Y')r=mid;
		else l=mid+1;
	}
	printf("! %d\n",r);
	return 0;
}