#include<cstdio>
const int MaxN=100010;
int N,x[MaxN],M,p[MaxN],q[MaxN];
long long ans[MaxN],K;
void swp(int&a,int&b){int t=a;a=b;b=t;}
bool vis[MaxN];
int list[MaxN];
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)scanf("%d",x+i),p[i]=i;
	scanf("%d%lld",&M,&K);
	while(M--){
		int a;scanf("%d",&a);
		swp(p[a-1],p[a]);
	}
	for(int i=0;i<=N;i++)if(!vis[i]){
		int len=0,j=i;
		for(;!vis[j];vis[j]=1,j=p[j])list[len++]=j;
		int r=K%len;
		for(int t=0;t<len;t++)
			p[list[t]]=list[r],r=(r+1)%len;
	}
	for(int i=0;i<=N;i++)q[p[i]]=i;
	for(int i=1;i<=N;i++)ans[q[i-1]]+=x[i],ans[q[i]]-=x[i];
	for(int i=0;i<N;i++)printf("%lld.0\n",ans[i]),ans[i+1]+=ans[i];
}