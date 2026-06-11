#include<bits/stdc++.h>
using namespace std;
#define N 1111116
#define next nxt

int n,m,x[N],y[N],next[N],p[N],h[N][2];
long long cnts,cnto,cnte;

int travel(int x,int k){
	h[x][k]=1;
	for (int t=p[x];t;t=next[t])
		if (!h[y[t]][k^1])
		travel(y[t],k^1);
	return h[x][k^1];
}

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')  f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		x[2*i-1]=y[2*i]=read();
		y[2*i-1]=x[2*i]=read();
		next[2*i-1]=p[x[2*i-1]];p[x[2*i-1]]=2*i-1;
		next[2*i]=p[x[2*i]];p[x[2*i]]=2*i;
	}
	for (int i=1;i<=n;i++)
		if (!p[i]) cnts++;
		else if (!h[i][0]&&!h[i][1])
			travel(i,0)?cnto++:cnte++;
	printf("%lld\n",cnts*(2*n-cnts)+(cnto+cnte)*(cnto+cnte)+cnte*cnte);
	return 0;
}