#include <algorithm>
#include <cstdio>

const int N=100005;

int f[N],cnt[N],n,m;

struct info{
	int l,r;
}a[N*3];

bool cmp(info a,info b){
	return a.r-a.l<b.r-b.l;
}

void add(int x,int y){
	for (;x<=m;x+=x&-x) f[x]+=y;
}

int sum(int x){
	int y=0;
	for (;x;x-=x&-x) y+=f[x];
	return y;
}

int main(){
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d\n",&a[i].l,&a[i].r);
		cnt[a[i].r-a[i].l]++;
	}
	for (int i=m;i;i--) cnt[i]+=cnt[i+1];
	std::sort(a+1,a+n+1,cmp);
	for (int i=1,j=1;i<=m;i++){
		for (;j<=n && a[j].r-a[j].l<i;j++){
			add(a[j].l,1);add(a[j].r+1,-1);
		}
		int ans=cnt[i];
		for (int k=i;k<=m;k+=i) ans+=sum(k);
		printf("%d\n",ans);
	}
}