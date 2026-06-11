#include<bits/stdc++.h>
using namespace std;
long long n,x[100010],tot,md,tmp,idx,cnt,tmpcnt,temp,diff;
bool ok;
int main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&x[i]);
		tot+=x[i];
	}
	md = (n*(n+1))/2;
	if(tot%md) printf("NO\n");
	else
	{	
		ok = 1;
		cnt = 1;
		tmp = tot/md;
		for(long long i=0;i<n;i++)
		{
			diff = x[(i+1)%n]-x[i]-tmp;
			if(diff>0 ||abs(diff)%n) 
			{
				ok = 0;
				break;
			}
		}
		printf("%s\n",ok?"YES":"NO");	
	}
	return 0;
}