#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define MAXN 200000
using namespace std;
int X[MAXN+5],W[MAXN+5];
int sum[2][MAXN+5],pos[MAXN+5];
int ans[MAXN+5];
int N,L,T;
int main()
{
	scanf("%d %d %d",&N,&L,&T);
	int T1=T;
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&X[i],&W[i]);
		pos[i]=X[i];
		sum[0][i]=sum[0][max((i-1),0)];
		sum[1][i]=sum[1][max((i-1),0)];
		W[i]--;
		sum[W[i]][i]++;
	}
	for(int i=N;i<2*N;i++)
	{
		pos[i]=X[i%N]+L;
		sum[0][i]=sum[0][i-1];
		sum[1][i]=sum[1][i-1];
		sum[W[i%N]][i]++;
	}
	int cnt[2]={};
	T*=2;
	cnt[0]=T/L*sum[0][N-1];
	cnt[1]=T/L*sum[1][N-1];
	T%=L;
	for(int i=0;i<N;i++)
	{
		if(W[i]==1)
			continue;
		int p=upper_bound(pos,pos+2*N,pos[i]+T)-pos;
		p--;
		int cntn=cnt[1]+sum[1][p]-sum[1][i];
		ans[(i+cntn)%N]=(pos[i]+T1)%L;
	}
	for(int i=N;i<2*N;i++)
	{
		if(W[i%N]==0)
			continue;
		int p=lower_bound(pos,pos+2*N,pos[i]-T)-pos;
		int cntn;
		if(p>0)
			cntn=cnt[0]+sum[0][i-1]-sum[0][p-1];
		else
			cntn=cnt[0]+sum[0][i-1];
		ans[((i-cntn)%N+N)%N]=((pos[i]-T1)%L+L)%L;
	}
	for(int i=0;i<N;i++)
		printf("%d\n",ans[i]);
	return 0;
}