#include<bits/stdc++.h>
#define N 100100
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;
	static int p;p=1;
	static char c;c=getchar();
	while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c-48);c=getchar();}
	x*=p;
}
int n,m;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
//	freopen("mnth.in","r",stdin);
//	freopen("mnth.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+n+1,cmp);
	int stx=1,sty=1;
	while(sty+1<=a[stx+1])sty++,stx++;
	int now=stx+1;
	while(a[now]==sty)now++;
	if((now-stx)%2==1&&(a[stx]+1-sty)%2==1)
		puts("Second");
	else puts("First");
	return 0;
}