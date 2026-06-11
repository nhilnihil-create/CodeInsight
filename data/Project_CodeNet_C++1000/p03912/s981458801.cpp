#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll inf=0xc0c0c0c0c0c0c0c0;
const double pi=acos(-1);
const int MAXM=1e5+7;
typedef map<int,int>::iterator IT;
int N,M,cnt;
map<int,int> tool[MAXM];
int odd[MAXM],pir[MAXM];
void solve(int a,int b)
{
	if(odd[a]>odd[b])
	{
		swap(odd[a],odd[b]);
		swap(pir[a],pir[b]);
	}
	int left=odd[b]-odd[a];
	int k=min(left>>1,pir[a]);
	odd[a]+=k<<1;
	pir[a]-=k;
	cnt+=odd[a];
	cnt+=pir[b]+pir[a];
}
void solve(int x)
{
	cnt+=pir[x];
	cnt+=odd[x]>>1;
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		int x;
		scanf("%d",&x);
		tool[x%M][x]++;
	}
	for(int i=0;i<M;i++)
	{
		for(IT it=tool[i].begin();it!=tool[i].end();it++)
		{
			pir[i]+=it->se>>1;
			if(it->se&1)
			{
				it->se--;
				odd[i]++;
			}
		}
	}
	cnt=0;
	solve(0);
	if((M&1)==0)solve(M>>1);
	for(int i=1;i<=((M-1)>>1);i++)
		solve(i,M-i);
	
	printf("%d",cnt);
	return 0;
}