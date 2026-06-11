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

#define N 100005
#define M 200005
#define seed 23333
#define Mo 1000000007

using namespace std;
int i,j,m,n,p,k,cnt=0,a[N],ans=1;
int fac(int x)
{
		int sum=1;
		for (i=1;i<=x;++i) sum=1ll*sum*i%Mo;
		return sum;
}
int main()
{
	scanf("%d",&n); int now=1;
	for (i=1;i<=n;++i) 
	{
			scanf("%d",&a[i]);
			if (now<=a[i]) now+=2,cnt+=1; 
			else ans=1ll*ans*(cnt+1)%Mo;
	}
	printf("%d\n",1ll*ans*fac(cnt)%Mo);
}
