#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
 
using namespace std;
const int N=105;
int n,a[N],x,mx;
 
int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}
 
bool check()
{
	if(mx==1) return n!=2;
	if(a[mx]==1) return 1;
	int mn=(mx+1)>>1;
	rep(i,1,mn-1) if(a[i]) return 1;
	rep(i,mn+1,mx) if((a[i]-=2)<0) return 1;
	if(mx&1) a[mn]-=2;
	else a[mn]-=1;
	if(a[mn]) return 1;
	return 0;
}

int main()
{
	n=getint();
	rep(i,1,n) mx=max(mx,x=getint()),++a[x];
	if(check()) puts("Impossible");
	else puts("Possible");
	return 0;
}