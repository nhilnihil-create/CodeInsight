#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

ll k;
int n,m;
int c[maxn];
bool bo[maxn];
ll a[maxn],ans[maxn];

int read() {
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*f;
}

int main() {
	n=read();
	for(int i=1;i<=n;i++)
	    scanf("%lld",a+i),c[i]=i;
	m=read();scanf("%lld",&k);
	for(int i=1;i<=m;i++) {
		int x=read();
		swap(c[x],c[x+1]);
	}
	for(int i=1;i<=n;i++)
		if(!bo[i]) {
			int u=i,cnt=0,step,goal;
			while(!bo[c[u]])
				bo[c[u]]=1,cnt++,u=c[u];
			step=k%cnt,goal=u=i;
			for(int j=1;j<=step;j++)
				goal=c[goal];
		    for(int j=1;j<=cnt;j++)
				ans[u]=goal,u=c[u],goal=c[goal];
		}
	for(int i=2;i<=n;i++) {
		int x=ans[i];
		ans[i]=a[x]-a[x-1];
	}
	ans[1]=a[1];
	for(int i=1;i<=n;i++)
		ans[i]+=ans[i-1],printf("%.1lf\n",(double)ans[i]);
	return 0;
}
