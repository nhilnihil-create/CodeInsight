#include<iostream>
#include<cstdio>
#include<cstdlib>
#define N 100010
using namespace std;
int num[N],n;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
bool work()
{
	
	return !work();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	bool ans=0;
	while(true)
	{
		int cnt=0;
		bool one=false;
		for(int i=1;i<=n;i++)
		{
			if(num[i]==1) one=true;
			if(num[i]&1) cnt++;
		}
	
		if((n-cnt)&1){ans^=1;break;}
		if(one || cnt>1)break;
	
		for(int i=1;i<=n;i++)
		if(num[i]&1) {num[i]--;break;}
	
		int g=num[1];
		for(int i=2;i<=n;i++) g=gcd(g,num[i]);
		for(int i=1;i<=n;i++) num[i]/=g;
		ans^=1;
	}
	puts(ans?"First":"Second");
	return 0;
}
