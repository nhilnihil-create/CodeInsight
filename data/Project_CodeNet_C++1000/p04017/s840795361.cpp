#include<bits/stdc++.h>
using namespace std;
#define f1(a,b,c) for(int c=a;c<=b;c++)
#define f2(a,b,c) for(int c=a;c>=b;c--)
#define f3(a,b,c) for(int c=a;c;c=b)
#define so1(a,n) sort(a+1,a+n+1,mycmp);
#define so2(a,n) sort(a+1,a+n+1);
#define ll long long
#define itn int
#define ubt int 
const int twx=1e5+100;
const int inf=0x7fffffff;
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
int x[twx];
int L,Q;
int a,b;
int asd[twx][40];
void init()
{
	n=read();
    f1(1,n,i)
    {
        x[i]=read();
    }
    L=read();
    Q=read();
    f1(1,n,i)
    {
        int LEFT=i+1;
        int RIGHT=n;
        while(LEFT<=RIGHT)
        {
            int MID=(LEFT+RIGHT)/2;
            if(x[MID]<=L+x[i])
            {
                LEFT=MID+1;
            }
            else
            {
                RIGHT=MID-1;
            }
        }
        if(x[i]+L>=x[n])
        {
            asd[i][0]=n;
        }
        else
        {
            asd[i][0]=LEFT-1;
        }
    } 
    f1(1,30,i)
    {
        f1(1,n,j)
        {
            asd[j][i]=asd[asd[j][i-1]][i-1];
        }
    }
    while(Q--)
    {
        int a=read();
        int b=read();
        if(b<a)
        {
            swap(a,b);
        }
        ll ans=0;
        f2(30,0,i)
        {
            if(asd[a][i]<b)
            {
                ans+=(1<<i);
                a=asd[a][i];
            }
        }
        printf("%lld\n",ans+1);
    }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    init();
	return 0;
}