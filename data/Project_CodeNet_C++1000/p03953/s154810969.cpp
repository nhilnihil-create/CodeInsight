#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m;
ll k;
int pos[N];
int hd[N],cnt;
int to[N][70];
bool vis[N];
int id[N],th[N];
int tot;
ll p[N];
int cha[N];
int ans[N];
int go[N];
int main()
{
	scanf("%d",&n);
	int las=0;
	for(int i=1;i<=n;i++) scanf("%lld",&p[i]),cha[i]=p[i]-las,las=p[i],pos[i]=i;
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d",&go[i]);
	}
	for(int i=1;i<=m;i++){
		swap(pos[go[i]],pos[go[i]+1]);
	}
	for(int i=1;i<=n;i++){
		//cout<<pos[i]<<" ";
		to[pos[i]][0]=i;
	}
	for(int j=1;j<=62;j++){
		for(int i=1;i<=n;i++){
			to[i][j]=to[to[i][j-1]][j-1];
		}
	}	
	ll o=k;
	for(int i=1;i<=n;i++){
		k=o;
		//cout<<" ----------- "<<i<<endl;
		int now=i;
		for(int j=62;j>=0;j--){
			if(k>=(1LL<<j)) {
				k-=(1LL<<j);
				now=to[now][j];
				//cout<<j<<" "<<now<<endl;
			}
		}
		//cout<<i<<" : "<<now<<endl;
		ans[now]=cha[i];
	}
	
	double sum=0.0;
	for(int i=1;i<=n;i++){
		sum+=1.0*ans[i];
		printf("%lf\n",sum);
	}
	return 0;
}