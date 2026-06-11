#include<cstdio>
#include<cctype>
#include<vector>
using namespace std;
const int N=1e5;
int n,a[N+1];
vector<int>e[N+1];
int root;
long long f[N+1];
bool res=true;
int read()
{
	int ret=0;
	char c=getchar();
	while(!isdigit(c)) {
		c=getchar();
	}
	while(isdigit(c)) {
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
void dfs(int u,int fa)
{
	long long maxf=0,sumf=0;
	for(int v:e[u]) {
		if(v==fa) {
			continue;
		}
		dfs(v,u);
		if(!res) {
			return;
		}
		maxf=max(maxf,f[v]),sumf+=f[v];
	}
	if(e[u].size()==1) {
		f[u]=a[u];
	} else {
		long long x=sumf-a[u],y=2*a[u]-sumf;
		if((x<0)||(y<0)||(x>min(sumf-maxf,sumf/2))||(!fa&&y)) {
			res=false;
		}
		f[u]=y;
	}
	return;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) {
		a[i]=read();
	}
	for(int i=1,u,v;i<n;++i) {
		u=read(),v=read();
		e[u].push_back(v),e[v].push_back(u);
	}
	if(n==2) {
		res=a[1]==a[2];
	} else {
		for(int i=1;i<=n;++i) {
			if(e[i].size()>1) {
				root=i;
				break;
			}
		}
		dfs(root,0);
	}
	puts(res?"YES":"NO");
	return 0;
}
