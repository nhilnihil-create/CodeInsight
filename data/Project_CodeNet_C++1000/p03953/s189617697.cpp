#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>

using namespace std;
const int MAXN = 100005;
typedef long long LL;

inline int rd(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) {f=ch=='-'?-1:1;ch=getchar();}
	while(isdigit(ch))  {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

struct Data{
	LL diff;
	int id;
}data[MAXN];

int n,m,a[MAXN];
int fa[MAXN],num;
LL now[MAXN<<1],ans[MAXN],sum[MAXN];
bool vis[MAXN];
LL k; 

int get(int x){
	if(vis[x]) return 0;
	now[++num]=x;
	vis[x]=1;
	return get(fa[x])+1;
}

int main(){
//	freopen("data.txt","r",stdin);
//	freopen("wrong.txt","w",stdout);
	n=rd();
	for(register int i=1;i<=n;i++){
		a[i]=rd();
		data[i].diff=a[i]-a[i-1],data[i].id=i;
	}
	m=rd();scanf("%lld",&k);
	for(register int i=1;i<=m;i++){
		int x=rd();
		swap(data[x],data[x+1]);
	}
	for(register int i=1;i<=n;i++)	{
		if(data[i].id==i) continue;
		fa[i]=data[i].id;
	}
	for(register int i=1;i<=n;i++){
		if(data[i].id==i) {
			ans[i]=data[i].diff;
			continue;
		}
		if(vis[i]) continue;
		int siz=get(i);
		for(register int j=1;j<=siz;j++) now[j+siz]=now[j];
		LL to=(k-1ll)%(LL)siz;
		for(register int j=1;j<=siz;j++) 
			ans[now[j]]=data[now[j+to]].diff;
		num=0;
	}
//	for(register int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
	for(register int i=1;i<=n;i++)
		ans[i]+=ans[i-1],printf("%lld.0\n",ans[i]);
	return 0; 
}