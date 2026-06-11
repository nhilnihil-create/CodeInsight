#include<bits/stdc++.h>
#define bug puts("QWQ")
#define huan putchar('\n')
#define kong putchar(' ')
using namespace std;

inline void read(int  &x)
{
	int pd=1;
	register char ch=getchar();x=0;
	while(ch<'0'||ch>'9'){if(ch=='-')pd=-pd;ch=getchar();}
 	while(ch>='0'&&ch<='9'){x=(x*10+ch-'0');ch=getchar();}
 	x*=pd;
}

void write(int x)
{
	if(x<0)x=-x,putchar('-');
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}

inline void wrl(int x)
{
	write(x);
	puts("");
}

inline void wrs(int x)
{
	write(x);
	putchar(' ');
}

/*
¿¼ÂÇÃ»ÓÐÄÃ×ßÒ»¶ÑµÄ²Ù×÷£¬ÄÇÃ´ÏÈÊÖ±Ø°ÜµÄÌõ¼þÊÇMX(A[I])ÊÇÆæÊý

¿¼ÂÇÃ»ÓÐ¼õÒ»µÄ²Ù×÷£¬ÄÇÃ´ÏÈÊÖ±Ø°ÜµÄÌõ¼þÊÇNÊÇÆæÊý 
*/

const int N=1e5+233;
int n,a[N];
inline bool check()
{
    for(register int i=1;i<=n;++i)
    {
        if(a[i])return 1;
    }
    return 0;
}
bool dfs(int s)
{
    if(!check())
    {
        return 1;
    }
    
    bool flag=1;
    bool vis[20];
    memset(vis,0,sizeof(vis));
    for(register int i=1;i<=n;++i)
    {
        if(a[i])
        --a[i],vis[i]=1;
    }
    flag&=dfs(s+1);
    for(register int i=1;i<=n;++i)
    {
        if(vis[i])
        ++a[i],vis[i]=0;
    }
    int now;
    for(register int i=1;i<=n;++i)
    {
        if(a[i])
        {
            now=a[i];
            a[i]=0;
            flag&=dfs(s+1);
            a[i]=now;
            break;
        }
    }
    return flag^1;
}


int main()
{
//    freopen("t1.in","r",stdin);
//    freopen("t1.out","w",stdout);
	int T;
//	read(T);
//	while(T--)
	{
		memset(a,0,sizeof(a));
		read(n);
		for(register int i=1;i<=n;++i)
		{
			read(a[i]);
		}
		sort(a+1,a+n+1,greater<int> ());
		for(register int i=1;i<=n;++i)
		{
			if(i>=a[i+1])
			{
				int ans=0;
				for(register int j=i+1;a[j]==i;++j)ans^=1;
				if(ans||((a[i]-i)&1))puts("First");
				else puts("Second");
				break;
			}
		}
	}
    return 0;
}