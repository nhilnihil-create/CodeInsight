#include<bits/stdc++.h>
using namespace std;
#define f1(a,b,c) for(int c=a;c<=b;c++)
#define f2(a,b,c) for(int c=a;c>=b;c--)
#define f3(a,b,c) for(int c=a;c;c=b)
#define so1(a,n) sort(a+1,a+n+1,mycmp);
#define so2(a,n) sort(a+1,a+n+1);
#define re(a,n) reverse(a+1,a+n+1);
#define ll long long
#define itn int
#define ubt int 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
const int twx=2e3+100;
const int inf=0x3f3f3f3f;
ll read()
{
    ll sum=0;
    ll flag=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
        {
            flag=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        sum=((sum*10)+c-'0');
        c=getchar();
    }
    return sum*flag;
}
int n,k;
struct LV
{
    int y;
    int Next;
}a[twx<<1];
int X[twx];
int Y[twx];
int Link[twx];
int len;
int cnt;
int ans=inf;
/*
一个显然的结论：
对于一个直径长度为K的树
若K为偶数，那么一定存在一个点，使得每个点到那个点的距离不超过K/2
若K为奇数，那么一定存在一个点，使得每个点到那个点的距离不超过(k-1)/2
*/
void Insert(int x,int y)
{
    a[++len].y=y;
    a[len].Next=Link[x];
    Link[x]=len;
}
void dfs(int x,int fa,int deep)
{
    if(deep>k)
    {
        cnt++;
    }
    f3(Link[x],a[i].Next,i)
    {
        int y=a[i].y;
        if(y!=fa)
        {
            dfs(y,x,deep+1);
        }
    }
}
void init()
{
	n=read();
    k=read();
    f1(1,n-1,i)
    {
        int x=read();
        int y=read();
        X[i]=x;
        Y[i]=y;
        Insert(x,y);
        Insert(y,x);
    }
}
void work()
{
	if(!(k&1))//k为偶数时
	{
		k>>=1;
	    f1(1,n-1,i)
	    {
	        cnt=0;
	        dfs(i,0,0);
	        ans=min(ans,cnt);
	    }
	}
	else//k为奇数时
	{
		k>>=1;
		f1(1,n-1,i)
		{
			cnt=0;
            dfs(X[i],Y[i],0);
            dfs(Y[i],X[i],0);
            ans=min(ans,cnt);
		}
	}
}
void print()
{
	cout<<ans;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	init();
	work();
	print();
	return 0;
}
