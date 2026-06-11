#include<cstdio>
#include<cctype>
#include<algorithm>
const int N=300007,M=100007;
int read(){int x=0,c=getchar();while(!isdigit(c))c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x;}
struct node{int l,r;}a[N];
int n,m,ans[M],t[M];
void add(int p,int v){for(;p<=m;p+=p&-p)t[p]+=v;}
void upd(int l,int r){add(l,1);if(r<m)add(r+1,-1);}
int ask(int p){int s=0;for(;p;p^=p&-p)s+=t[p];return s;}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i) a[i].l=read(),a[i].r=read();
    std::sort(a+1,a+n+1,[](node&a,node&b){return a.r-a.l<b.r-b.l;});
    for(int i=1,p=1,s;i<=m;++i)
    {
	for(s=0;p<=n&&a[p].r-a[p].l<i;++p) upd(a[p].l,a[p].r);
	for(int j=i;j<=m;j+=i) s+=ask(j);
	printf("%d\n",n-p+1+s);
    }
}
