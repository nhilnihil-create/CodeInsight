#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define Fengexian cout<<"WZY%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl
const LL N = 1e5 + 10;
const LL mod = 998244353;
const LL inf = 0x3f3f3f3f;
const double eps = 1e-9;
using namespace std;
template <typename tp>
inline void read(tp &x)
{
	x = 0; char c = getchar(); bool f = 0;
	for (; c < '0' || c > '9'; f |= (c == '-'), c = getchar()) ;
	for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar()) ;
	if (f) x = -x;
}
int n,a[N],num[N],maxn,flag;
signed main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]),num[a[i]]++,maxn=max(maxn,a[i]);
	for(int i=maxn;i>=0;i--)
	{
		int zz=max(maxn-i,i);
		if(!num[zz]) return 0*puts("Impossible");
		num[zz]--;
	}
	for(int i=1;i<=((maxn+1)>>1);i++)
		if(num[i])
			return 0*puts("Impossible");
	return 0*puts("Possible");
}
