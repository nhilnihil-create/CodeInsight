#include <bits/stdc++.h>

using namespace std;
long long k;
int main()
{
	cin >>k;
	printf("%d\n",50);
	long long t1=k%50,t2=k/50;
	for(int i=1;i<=t1;i++)
		printf("%lld ",t2-t1+51+49);
	for(int i=t1+1;i<=50;i++)
		printf("%lld ",t2-t1+49); puts("");
	return 0;
}