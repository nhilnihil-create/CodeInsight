#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
long long k,n;
int num[100005];
int pos,mk=INT_MAX;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&num[i]);
    	if(mk>num[i])pos=i,mk=num[i];
    	k+=num[i];
	}
	if(k%(((n+1)*n)/2)==0)
	{
		long long c=k/(((n+1)*n)/2);
		bool p=true;
		if((long long)c*(long long)n>999999999)
		{
			c=k/(((n+1)*n)/2);
			bool p=true;
			c=c*(n-1);
			if(abs(num[n]-num[1])>c)p=false;
			for(int i=1;i<n;i++)
			{
				if(abs(num[i]-num[i+1])>c)p=false;
			}
		}
		else
		{
			while(c--)
			{
				int poss;
				for(int i=pos;i<=n;i++)
				{
					num[i]-=(i-pos+1);
					if(mk>num[i])mk=num[i],poss=i;
				}
				for(int i=1;i<pos;i++)
				{
					num[i]-=(i+(n-pos)+1);
					if(mk>num[i])mk=num[i],poss=i;
				}	
				pos=poss;
				/*for(int i=1;i<=n;i++)
				{
					printf("%d ",num[i]);
				}
				printf("pos %d %d\n",pos,mk);*/
				if(mk<=0)break;
				mk=INT_MAX;
			}
			for(int i=1;i<=n;i++)
			{
				//printf("%d ",num[i]);
				if(num[i]!=0)p=false;
			}	
		}
		if(p)printf("YES");
		else printf("NO");
	}
	else
	{
		printf("NO");
	}
}

