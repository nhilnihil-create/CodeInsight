#include<cstdio>
#include<algorithm>
#define N 550
using namespace std;
inline char gc(){
	static char now[1<<16],*S,*T;
	if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
	return *S++;
}
inline int read(){
	int x=0;char ch=gc();
	while (ch<'0'||ch>'9') ch=gc();
	while (ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=gc();}
	return x;
}
struct node{
	int num,pos;
}data[N];
inline bool cmp(node a,node b){
	return a.num<b.num;
}
int cnt[N],ans[N*N],n,mark[N];
int main(){
//	freopen("agc.in","r",stdin);
	n=read();
	for (int i=1;i<=n;++i) data[i].num=read(),data[i].pos=i,mark[i]=data[i].num;
	sort(data+1,data+n+1,cmp);int nn=n*n;
	for (int i=1;i<=n;++i) cnt[i]=n;
	for (int i=1;i<=n;++i){
		int pos=data[i].pos;ans[data[i].num]=pos;cnt[pos]--;int tmp=data[i].num-1;int tot=pos-1;if (!tot) continue;
		for (int j=1;j<=tmp;++j){
			if (ans[j]) continue;
			ans[j]=pos;tot--;cnt[pos]--;if (tot==0) break;
		}if (tot>0){printf("No");return 0;}
	}
	int id=0;
	for (int i=1;i<=nn;++i){
		if (!ans[i]){id=0;
			if (!cnt[id]){
				for (int j=1;j<=n;++j){
				if(mark[j]<i&&cnt[j]) id=j;
				}
			}
			if (!id) {printf("No");return 0;}
			ans[i]=id;cnt[id]--;
		}
	}printf("Yes\n");
	for (int i=1;i<=nn;++i) printf("%d ",ans[i]);
	return 0;
}