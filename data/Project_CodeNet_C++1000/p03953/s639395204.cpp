#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
long long k,n,m,i,j,a[100005],d[100005],f[100005],g[100005],h[100005];
int main()
{
	scanf("%lld",&n);
	fz1(i,n){
		scanf("%lld",&a[i]);
	}
	fz1(i,n-1){
		d[i]=a[i+1]-a[i];
		f[i]=g[i]=i;
	}
	scanf("%lld%lld",&m,&k);
	fz1(i,m){
		int x;
		scanf("%lld",&x);
		swap(f[x-1],f[x]);
	}
	while(k)
	{
		if(k&1){
			fz1(i,n-1){
				g[i]=f[g[i]];
			}
		}
		fz1(i,n-1){
			h[i]=f[f[i]];
		}
		fz1(i,n-1){
			f[i]=h[i];
		}
		k/=2;
	}
	fz1(i,n){
		if(i!=1){
			a[i]=a[i-1]+d[g[i-1]];
		}
		printf("%lld.0\n",a[i]);
	}
	return 0;
}