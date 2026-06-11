#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=200005;
int n,a[N],m;
int s[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool check(int x)
{
	rep(i,1,m) s[i]=(a[i]>x);
	int p,q;
	rep(i,n,m) if(s[i]==s[n]) q=i; else break;
	repd(i,n,1) if(s[i]==s[n]) p=i; else break;
	if(q-p) return !s[n];
	p=n+1;
	while(p<m)
	{
		if(s[p]==s[p+1]) break;
		++p;
	}
	q=n-1;
	while(q>1)
	{
		if(s[q]==s[q-1]) break;
		--q;
	}
	if(p<m && q>1)
	{
		if(!s[q] && !s[p]) return 1;
		if(s[q] && s[p]) return 0;
		if(s[q] && !s[p]) return p-n<n-q;
		if(!s[q] && s[p]) return p-n>n-q;
	}
	if(p==m && q==1) return !s[1];
	return p<m?!s[p]:!s[q];
}

int main()
{
	n=getint(),m=2*n-1;
	rep(i,1,m) a[i]=getint();
	int l=1,r=m;
	while(l<=r) check(mid)?r=mid-1:l=mid+1;
	printf("%d\n",r+1);
	return 0;
}