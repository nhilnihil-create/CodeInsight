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
const int twx=2e5+100;
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
int n;
int a[twx];
int l[twx];
int r[twx];
ll ans=0;
int pos[twx];
void init()
{
	n=read();
    r[0]=1;
    l[n+1]=n;
    f1(1,n,i)
    {
        int x=read();
        l[i]=i-1;
        r[i]=i+1;
        pos[x]=i;
    }
}
void work()
{
    f2(n,1,i)
    {
        ans+=1LL*i*(pos[i]-l[pos[i]])*(r[pos[i]]-pos[i]);
        r[l[pos[i]]]=r[pos[i]];
		l[r[pos[i]]]=l[pos[i]];
    }
}
void print()
{
	printf("%lld\n",ans);
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