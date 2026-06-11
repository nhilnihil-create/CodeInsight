#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,K,a[100010],dep[100010];
int q[100010],head=0,tail=0,cnt[100010];
int main(){
	int i,u,ans=0;
	n=read();K=read();
	a[1]=read();
	if(a[1]!=1) ans++,a[1]=1;
	for(i=2;i<=n;i++) a[i]=read(),cnt[a[i]]++;
//	for(i=1;i<=n;i++) cout<<cnt[i]<<ends;cout<<endl;
	for(i=1;i<=n;i++) if(!cnt[i]) q[tail++]=i;
	while(head<tail){
		u=q[head++];
//		cout<<"topo "<<u<<ends<<dep[u]<<endl;
		if(u==1) break;
		if(a[u]!=1&&dep[u]==K-1) ans++;
		else dep[a[u]]=max(dep[a[u]],dep[u]+1);
		cnt[a[u]]--;
		if(cnt[a[u]]==0) q[tail++]=a[u];
	}
	printf("%d\n",ans);
}