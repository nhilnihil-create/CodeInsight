#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 100010
using namespace std;
long long num[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
	sort(num+1,num+n+1,greater<int>());
	for(int i=2;i<=n+1;i++)
	if(i-1<=num[i-1] && i>num[i])
	{
		int x=i-1;
		if((num[x]-x)%2==1){puts("First");return 0;}
		while(num[x+1]+1==i) x++;
		if((x-i+1)%2==0){puts("Second");return 0;}
		puts("First");
		return 0;
	}
	return 0;
}
