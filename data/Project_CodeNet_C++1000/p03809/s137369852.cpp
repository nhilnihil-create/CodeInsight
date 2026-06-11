#include<bits/stdc++.h>
using namespace std;
#define N 1111116
#define next nxt

int n,t,x[N],y[N],next[N],p[N],d[N],f[N];
long long a[N];

void travel(int x){
	if (d[x]==1) return;
	long long cnt=0,mx=0;
	for (int t=p[x];t;t=next[t])
		if (y[t]!=f[x]){
			f[y[t]]=x;travel(y[t]);
			cnt+=a[y[t]];
			mx=max(mx,a[y[t]]);
		}
	if (mx>a[x]||cnt<a[x]||cnt>2*a[x])
	{printf("NO\n");exit(0);}
	a[x]=2*a[x]-cnt;
}

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')  f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n-1;i++){
		x[2*i-1]=y[2*i]=read();
		y[2*i-1]=x[2*i]=read();
		d[x[2*i-1]]++;d[y[2*i-1]]++;
		next[2*i-1]=p[x[2*i-1]];p[x[2*i-1]]=2*i-1;
		next[2*i]=p[x[2*i]];p[x[2*i]]=2*i;
	}
	if (n==2){
		printf(a[1]!=a[2]?"NO\n":"YES\n");
		return 0;
	}
	for (t=1;d[t]==1;t++);
	travel(t);
	printf(a[t]?"NO\n":"YES\n");
	return 0;
}