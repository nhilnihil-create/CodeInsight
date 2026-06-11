#include<cstdio>
const int N=2e5+5;
int n,m,i,now,x,y,et,he[N],g[N],cnt;
long long sum,ans;
struct edge{int l,x;}e[N];
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
void line(int x,int y){
	e[++et].l=he[x];he[x]=et;e[et].x=y;
}
void add(int x,int k){
	for (int i=he[x];i;i=e[i].l){
		int y=e[i].x;
		if (y<=now) sum-=(now-y)*k,cnt+=k;
		if (y>0&&y<=m) g[y]+=k;
	}
}
int main(){
	n=read();m=read();x=read();
	for (i=2;i<=n;i++){
		y=x;x=read();
		if (y<=x) sum+=x-y,line(x,y);
		else sum+=m+x-y,line(x,y-m),line(x+m,y);
	}
	ans=sum;
	for (i=1;i<=m;i++) add(i,1);
	for (now=1;now<=m;now++){
		if (sum<ans) ans=sum;
		sum-=cnt;cnt+=g[now];
		add(now,-1);add(now+m,1);	
	}
	printf("%lld",ans);
}