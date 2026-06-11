#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define ll long long
using namespace std;
 
const int N=100005;
 
struct E{
	int to,next;
}mem[N<<1];
int n,num,x,y,rt;
ll all;
bool tag;
int head[N],d[N];
ll a[N],dp[N],b[N];
 
void add(int x,int y){
	num++;
	mem[num].to=y; mem[num].next=head[x];
	head[x]=num;
}
 
void dfs(int k,int pre){
	int j,u,cnt=0,mx,sum;
	if (!tag) return;
	if (d[k]==1) return;
	for (j=head[k];j;j=mem[j].next){
		u=mem[j].to;
		if (u==pre) continue;
		dfs(u,k);
	}
	for (j=head[k];j;j=mem[j].next){
		u=mem[j].to;
		if (u==pre) continue;
		b[++cnt]=dp[u];
	}
	if (!tag) return;
	sort(b+1,b+1+cnt);
	mx=0; sum=0;
	for (j=1;j<=cnt;j++) sum+=b[j];
	if (a[k]>sum){
		printf("NO\n");
		tag=0;
		return;
	}
	if (b[cnt]>sum/2) mx=sum-b[cnt];
	else mx=sum/2;
	if (a[k]<sum-mx){
		printf("NO\n");
		tag=0;
		return;
	}
	dp[k]=2ll*a[k]-sum;
}
 
int main(){
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		d[x]++; d[y]++;
	}
	if (n==2){
		if (a[1]!=a[2]) printf("NO\n");
		else printf("YES\n");
		return 0;
	}
	tag=1;
	for (i=1;i<=n;i++)
		if (d[i]>1){
			rt=i;
			break;
		}
	for (i=1;i<=n;i++)
		if (d[i]==1){
			dp[i]=a[i];
			all+=a[i];
		}
	dfs(rt,0);
	if (tag){
		if (dp[rt]) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}