#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005;
long long num[N],dif[N],pos[N];
long long mov[N],dfn[N],col[N];
vector<long long> cir[N];
long long n,m,k,cnt,las;
void DFS(long long nde,long long len)
{
	dfn[nde]=len,col[nde]=cnt;
	cir[cnt].push_back(nde);
	if(!col[pos[nde]])
		DFS(pos[nde],len+1);
}
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&num[i]),pos[i]=i,dif[i-1]=num[i]-num[i-1];
	scanf("%lld%lld",&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld",&mov[i]),swap(pos[mov[i]],pos[mov[i]-1]);
	for(int i=1;i<=n;i++)
		if(!dfn[i]) cnt++,DFS(i,0);
	las=num[1],printf("%lld\n",las);
	for(int i=1;i<n;i++)
		printf("%lld\n",las+=dif[cir[col[i]][(dfn[i]+k)%cir[col[i]].size()]]);
	return 0;
}