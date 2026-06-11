#include<bits/stdc++.h>

using namespace std;

#define N 120000

int n,m,ans,a[N],d[N],f[N],q[N];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	if (a[1]!=1){++ans; a[1]=1;}
	for (int i=2;i<=n;++i) ++d[a[i]];
	int t=0,w=0;
	for (int i=2;i<=n;++i){
		if (!d[i]) q[++w]=i;
		f[i]=m;
	}
	++d[1];
	while (t<w){
		int x=q[++t];
		if (f[x]==1&&a[x]!=1) ++ans;
		else f[a[x]]=min(f[a[x]],f[x]-1);
		--d[a[x]];
		if (!d[a[x]]) q[++w]=a[x];
	}
	printf("%d\n",ans);
	
	return 0;
}
			