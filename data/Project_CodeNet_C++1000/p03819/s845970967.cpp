#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 100005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,ans;
struct info
{
	int l,r;
	friend bool operator<(info t1,info t2) {return t1.r-t1.l<t2.r-t2.l;}
}A[N*3];
class BIT
{
	int t[N];
public:
	void add(int x,int v) {for(;x<=m;x+=x&-x) t[x]+=v;}
	int ask(int x) {int res=0;for(;x;x-=x&-x) res+=t[x];return res;}
}B;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&A[i].l,&A[i].r);
	std::sort(A+1,A+1+n);
	for(int i=1,j=1;i<=m;i++)
	{
		for(;A[j].r-A[j].l+1<i&&j<=n;j++) B.add(A[j].l,1),B.add(A[j].r+1,-1);
		ans=n-j+1;
		for(int k=i;k<=m;k+=i) ans+=B.ask(k);
		printf("%d\n",ans);
	}
	return 0;
}