#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=400005;
int ne[N],fi[N],zz[N],tot,n,m,flag[N],Flag,x,y;
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
void dfs(int x){
	for (int i=fi[x];i;i=ne[i]){
		if (flag[zz[i]]){
			if (flag[zz[i]]==flag[x])Flag=1;
			continue;
		}
		flag[zz[i]]=3-flag[x];
		dfs(zz[i]);
	}
}
signed main(){
	scanf("%lld%lld",&n,&m);
	while (m--){
		scanf("%lld%lld",&x,&y);
		jb(x,y);jb(y,x);
	}
	int cnt=0,cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++)
		if (!flag[i]){
			if (!fi[i]){
				cnt++;
				continue;
			}
			flag[i]=1;Flag=0;dfs(i);
			if (Flag)cnt1++;
			else cnt2++;
		}
	int ans=0,now=2*n-1;
	while (cnt--)ans+=now,now-=2;
	ans+=cnt1*cnt2*2+cnt2*cnt2*2+cnt1*cnt1;
	printf("%lld\n",ans);
}