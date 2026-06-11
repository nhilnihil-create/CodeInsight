#include <bits/stdc++.h>
using namespace std;

template <typename _Tp> inline _Tp read(_Tp&x){
	char c11=getchar(),ob=0;x=0;
	while(c11^'-'&&!isdigit(c11))c11=getchar();if(c11=='-')ob=1,c11=getchar();
	while(isdigit(c11))x=x*10+c11-'0',c11=getchar();if(ob)x=-x;return x;
}

const int N=101000;
struct Edge{int v,nxt;}a[N];
int head[N],n,k,_,ans;

int dfs(int x){
	int res=1,t;
	for(int i=head[x];i;i=a[i].nxt){
		t=dfs(a[i].v);
		if(t>=k&&x!=1)++ans,t=-1;
		res=max(res,t+1);
	}
	return res;
}

int main(){
	read(n),read(k);
	int x;read(x);if(x!=1)++ans;
	for(int i=2;i<=n;++i)
		read(x),a[++_].v=i,a[_].nxt=head[x],head[x]=_;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}