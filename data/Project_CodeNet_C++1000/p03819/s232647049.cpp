#include<cstdio>
const int N=1e5+5,M=3e5+5;
int n,m,i,ans,he[N],f[N];
struct edge{int l,to;}e[M];
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
void write(int x){if (x>9) write(x/10);putchar(x%10+48);}
void add(int x,int k){for (;x<=n;x+=x&-x) f[x]+=k;}
int ask(int x){int k=0;for (;x;x-=x&-x) k+=f[x];return k;}
int main(){
	for (m=read(),n=read(),i=1;i<=m;i++){
		int l=read(),r=read();
		e[i].l=he[r-l+1];he[r-l+1]=i;e[i].to=l;
	}
	for (int x=1;x<=n;x++){
		for (ans=m,i=x;i<=n;i+=x) ans+=ask(i);
		write(ans);putchar('\n');
		for (i=he[x];i;i=e[i].l)
			m--,add(e[i].to,1),add(e[i].to+x,-1);
	}
}