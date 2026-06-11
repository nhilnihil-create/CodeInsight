#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define pb push_back
typedef double db;
typedef long long ll;
typedef pair<int,int> P;
const int MAXN=3e5+10;
struct Interval{int l,r,len;}itv[MAXN];
int n,m,res,bit[MAXN];

bool cmp(Interval a,Interval b)
{return a.len<b.len;}
void Update(int k,int x)
{while(k<=m) bit[k]+=x,k+=k&(-k);}
int Query(int k)
{int ret=0;while(k) ret+=bit[k],k-=k&(-k);return ret;}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&itv[i].l,&itv[i].r),itv[i].len=itv[i].r-itv[i].l+1;
	sort(itv+1,itv+n+1,cmp);
	
	int k=1;
	for(int i=1;i<=m;i++)
	{
		while(itv[k].len<=i&&k<=n)
			Update(itv[k].l,1),Update(itv[k].r+1,-1),k++;
		res=n-k+1;
		for(int j=i;j<=m;j+=i)
			res+=Query(j);
		printf("%d\n",res);
	}
	return 0;
}