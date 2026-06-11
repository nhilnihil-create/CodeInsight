#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005;

int n,a[MAXN],b[MAXN];
bool check(int mid)
{
	for(int i=1;i<=2*n-1;++i)b[i]=(a[i]>=mid);
	int l=n,r=n;
	while(l>=2 && b[l-1]!=b[l])--l;
	while(r<=2*n-2 && b[r+1]!=b[r])++r;
	if(b[l]==b[r])return b[l];
	int t=(l+r)>>1;
	if(n<=t)return b[l];
	else return b[r];
}

int main()
{
	readint(n);
	for(int i=1;i<=2*n-1;++i)readint(a[i]);
	int L=1,R=2*n-1,mid,ans=0;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(check(mid))ans=mid,L=mid+1;
		else R=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}