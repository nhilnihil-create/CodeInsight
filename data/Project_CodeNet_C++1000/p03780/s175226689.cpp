#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<bitset>
using namespace std;
int n,k,a[5010];
bitset<5010> sum;
bool judge(int x)
{
    if(a[x]>=k)
	{
		return 1;
    }
	sum.reset(); 
	sum[0]=1;
    for(int i=1;i<=n;++i) 
	{
		if(i!=x)
		{
			sum|=sum<<a[i];
		}
	}
	for(int i=k-1;i>=k-a[x];--i)
	{
        if(sum[i]) 
		{
			return 1;
		}
	}
	return 0;
}

void solve()
{
    int l=0,r=n+1;
    while(l<r)
	{
        int mid=(l+r)>>1;
        if(judge(mid))
		{
			r=mid;
        }
		else 
		{
			l=mid+1;
		}
	}
    printf("%d",l-1);
}
void read(int &x)
{
	x=0;
	int f=1;
	char s=getchar();
	while(s<'0'||s>'9')
	{
		if(s=='-')
		{
			f=-1;
		}
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x<<3)+(x<<1)+s-'0';
		s=getchar();
	}
	x*=f;
}
int main()
{
    read(n);read(k);
    for(int i=1;i<=n;++i)
	{
		read(a[i]);
    }
	sort(a+1, a+n+1);
    solve();
    return 0;
}