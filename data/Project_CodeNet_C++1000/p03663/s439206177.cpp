#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
char s[10];
typedef long long LL;

bool query(LL x)
{
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='Y';
}

void solve1()
{
	int x=1;
	rep(i,0,9)
	{
		if(query(x*9ll))
		{
			printf("! %d\n",x);
			fflush(stdout);
			break;
		}
		x*=10;
	}
}

void solve3(int l,int r)
{
	while(l<=r) query(mid*10ll)?r=mid-1:l=mid+1;
	printf("! %d\n",r+1);
	fflush(stdout);
}

void solve2()
{
	int x=1;
	rep(i,0,9)
	{
		if(!query(x))
		{
			solve3(x/10,x-1);
			break;
		}
		x*=10;
	}
}

int main()
{
	if(query(1000000000)) solve1();
	else solve2();
	return 0;
}