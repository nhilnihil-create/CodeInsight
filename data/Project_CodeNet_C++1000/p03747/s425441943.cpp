#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
#define el putchar('\n')
#define ta putchar('	')
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
//	sprintf(str,"%s.out",s);
//	freopen(str,"w",stdout);
	#endif
}
inline int rd()
{
	static int x,f;
	x=0;f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=100010;
int n,L,T,a[N];

int main()
{
//	open("a");
	n=rd();L=rd();T=rd();
	ll p=1;
	fo(i,1,n){
		int x=rd(),y=rd();
		if(y==1){
			a[i]=(x+T)%L;
			p=(p+(x+T)/L%n)%n;
		}
		else{
			a[i]=(x-T%L+L)%L;
			p=(p+n-(T+L-1-x)/L%n)%n;
		}
	}
	sort(a+1,a+n+1);if(p==0)p=n;
	fo(i,p,n)printf("%d\n",a[i]);
	fo(i,1,p-1)printf("%d\n",a[i]);
	return 0;
}
