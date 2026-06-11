#include <bits/stdc++.h>
using namespace std;
#define N 110000
int n,num;
int a[N];
int main()
{
	scanf("%d",&n);
	if(n==1)return puts("Second"),0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(1)
	{
		int odd=0,even=0,pos;
		for(int i=1;i<=n;i++)
		{
			if(a[i]&1)odd++,pos=i;
			else even++;
		}
		if(even&1)break;
		if(odd>=2){num++;break;}
		if(a[pos]==1){num++;break;}
		a[pos]--;int t=a[1];
		for(int i=2;i<=n;i++)t=__gcd(t,a[i]);
		for(int i=1;i<=n;i++)a[i]/=t;
		num++;
	}
	puts(num&1 ? "Second" : "First");
	return 0;
}
