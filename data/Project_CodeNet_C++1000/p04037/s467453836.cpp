#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n,a[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	sort(a+1,a+1+n);
	int x=1,y=0;
	rep(i,2,n)
		if(++x,a[x-1]>y+1)
			--x,++y;
		
	int tot=0;
	rep(i,1,x-1) if(a[i]==y+1) ++tot;
	if(((a[x]-y+1)&1) || tot&1) puts("First");
	else puts("Second");
	return 0;
}	