#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 555
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f;
}
struct pt{
	int val,pos;
}v[N];
inline bool cmp(pt x,pt y){
	return x.val<y.val;
}
int cnt[N],ans[N*N],vis[N];
signed main(){
	int n=read();
	for (int i=1;i<=n;++i) v[i].val=read(),v[i].pos=i,vis[i]=v[i].val;
	sort(v+1,v+1+n,cmp);
	for (int i=1;i<=n;++i) cnt[i]=n;
	for (int i=1;i<=n;++i){
		int pos=v[i].pos;ans[v[i].val]=pos;cnt[pos]--;
		int tmp=v[i].val-1;int tot=pos-1;if (!tot) continue;
		for (int j=1;j<=tmp;++j){
			if (ans[j]) continue;
			ans[j]=pos;tot--;cnt[pos]--;if (tot==0) break;
		}
		if (tot>0){
			puts("No");return 0;
		}
	}
	for (int i=1;i<=n*n;++i){
		if (!ans[i]){
			int id=0;
			if (!cnt[id]){
				for (int j=1;j<=n;++j){
					if (vis[j]<i && cnt[j]) id=j;
				}
			}
			if (!id){
				puts("No");return 0;
			}
			ans[i]=id;cnt[id]--;
		}
	}
	puts("Yes");
	for (int i=1;i<=n*n;++i) printf("%d ",ans[i]);putchar('\n');
	return 0;
}
