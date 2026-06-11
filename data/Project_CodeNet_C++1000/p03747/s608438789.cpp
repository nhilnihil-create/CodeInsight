#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n,L,T,x,w,a[N],id;

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
	n=getint(),L=getint(),T=getint();
	rep(i,1,n)
	{
		x=getint(),w=getint()==2?-1:1;
		int dis=x+w*T;
		if(dis>0) id=(id+dis/L)%n;
		if(dis<0) id=(id+(dis+1)/L-1)%n;
		a[i]=(dis%L+L)%L;
	}
	sort(a+1,a+1+n),id=(id+n)%n;
	rep(i,id+1,n) printf("%d\n",a[i]);
	rep(i,1,id) printf("%d\n",a[i]);
	return 0;
}