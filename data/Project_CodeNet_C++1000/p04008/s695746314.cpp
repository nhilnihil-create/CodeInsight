#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
	int k,next;
}e[200005];
int n,a[100005],dep[100005],m,IN[100005],home[100005],cnt=-1;
void add(int x,int y){
	cnt++;
	e[cnt].k=y;
	e[cnt].next=home[x];
	home[x]=cnt;
}
int mx[100005];
void dfs1(int k){
	IN[a[k]]--;
	mx[a[k]]=max(mx[a[k]],mx[k]);
	if(!IN[a[k]]) dfs1(a[k]);
}
int f[100005];
void calc(int k){
	mx[k]=dep[k];
	int t=0;
	if(m==1&&dep[k]>1) t=1;
	for(int i=home[k];~i;i=e[i].next){
		dep[e[i].k]=dep[k]+1;
		calc(e[i].k);
		mx[k]=max(mx[k],mx[e[i].k]);
		if(mx[e[i].k]-dep[k]+1==m&&dep[k]>1) t=1; 
		f[k]+=f[e[i].k];
	}
	if(t) mx[k]=0;
	f[k]+=t;
}
int main(){
	memset(home,-1,sizeof(home));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),IN[a[i]]++;
	for(int i=2;i<=n;i++) add(a[i],i);
	int g=a[1],sum=1;
	while(g!=1) g=a[g],sum++;
	calc(1);
	if(m>n-1){
		for(int i=1;i<=n;i++){
			if((m-dep[i])%sum!=0) return printf("%d",a[1]!=1),0;
		}
		return puts("0"),0;
	}
	for(int i=1;i<=n;i++){
		if(dep[i]<=m&&(m-dep[i])%sum!=0) return printf("%d",f[1]+(a[1]!=1)),0;
	}
	printf("%d",f[1]);
	return 0;
}