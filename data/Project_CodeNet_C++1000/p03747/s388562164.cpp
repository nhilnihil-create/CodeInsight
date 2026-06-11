#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;
//scp_05_tqr(也就是大号的提交，别棕qwq)
int x[MAXN],bb[MAXN],w[MAXN];
int i,j,k,l,r,s,t,n,m;
ll c;

template<class T>inline void read(T &res)
{
	static char ch;T flag=1;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')flag=-1;res=ch-48;
	while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-48;res*=flag;
}

int main()
{
	read(n);read(l);read(t);
	for (int i=1;i<=n;i++)
    	scanf("%d%d",&x[i],&w[i]);
    for (int i=1;i<=n;i++)
    {
        if (w[i]==2)
        	w[i]=-1;
        r=x[i]+w[i]*t;
        if (r>0)
        	(c+=r/l)%=n;
        else if (r<0) (c+=(r+1)/l-1)%=n;
        bb[i]=(r%l+l)%l;
    }
    sort(bb+1,bb+n+1);
    c=(c+n)%n;
    for (int i=c+1;i<=n;i++)
    	printf("%d\n",bb[i]);
    for (int i=1;i<=c;i++)
    	printf("%d\n",bb[i]);
    return 0;
}