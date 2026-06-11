#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 5005
#define M 200005
#define seed 23333
#define Mo 1000000007

using namespace std;
int i,j,m,n,p,k,f[N][N],ans;
char c[N];
int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
				if (y&1) sum=1ll*sum*x%Mo;
				x=1ll*x*x%Mo;
		}
		return sum;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",c); m=strlen(c);
	f[0][0]=1;
	for (i=1;i<=n;++i)
	{
			(f[i][0]+=f[i-1][0])%=Mo;
			for (j=0;j<i;++j)
			{
					(f[i][j+1]+=f[i-1][j]*2%Mo)%=Mo;
					if (j)
					(f[i][j-1]+=f[i-1][j])%=Mo;
			}
	}
	printf("%d\n",1ll*f[n][m]*power(power(2,m),Mo-2)%Mo);
}
