#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 200005
#define INF 0x3f3f3f3f
#define LL long long
LL x,y;
LL Abs(LL m)
{
	if(m>=0) return m;
	return -m;
}
int main()
{
	scanf("%lld %lld",&x,&y);
	if(Abs(x-y)<=1)
		printf("Brown\n");
	else printf("Alice\n");
    return 0;
}
