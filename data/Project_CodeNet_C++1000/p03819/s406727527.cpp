#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=100005;
int n,m,t1[N],t2[N],tot;
vector <int> vt[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;	
	return x;
}

void ins(int t[],int x)
{
	for(int i=x+1; i<=m+1; i+=i&-i) ++t[i];
}

int query(int t[],int x)
{
	if(x<0) return 0;
	int rt=0;
	for(int i=x+1; i; i-=i&-i) rt+=t[i];
	return rt;
}

int query(int t[],int l,int r)
{
	r=min(r,m);
	return query(t,r)-query(t,l-1);
}

int solve(int p)
{
	LL ans=0;
	int sz=vt[p].size();
	rep(i,0,sz-1) ins(t1,vt[p][i]),ins(t2,vt[p][i]+p-1),++tot;
	rep(i,0,m/p)
	{
		int l=i*p,r=(i+1)*p-1;
		ans+=(LL)(query(t2,l,r)-query(t1,l,r))*i;
	}
	return ans+n-tot;
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n)
	{
		int l=getint(),r=getint();
		vt[r-l+2].pb(l-1);
	}
	rep(i,1,m) printf("%d\n",solve(i));
	return 0;
}