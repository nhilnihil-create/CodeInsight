#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x,y;
int main()
{
	scanf("%lld%lld",&x,&y);
	if(abs(x-y)>=2)
		printf("Alice\n");
	else
		printf("Brown\n");
	return 0;
}
