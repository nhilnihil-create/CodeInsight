#include<bits/stdc++.h>
const int N=1e5+7;
typedef long long i64;
std::vector<int>e[N];
int n,flag=1,rt=1;
i64 a[N];
void f1(int w,int pa){
	if(w!=rt&&e[w].size()==1)return;
	i64 sum=0,mx=0;
	for(int i=0;i<e[w].size();++i){
		int u=e[w][i];
		if(u!=pa){
			f1(u,w);
			sum+=a[u];
			if(a[u]>mx)mx=a[u];
		}
	}
	if(sum<a[w]||sum>a[w]*2||(mx*2>sum?sum-mx:sum/2)<sum-a[w])flag=0;
	a[w]=a[w]*2-sum;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",a+i);
	for(int i=1,a,b;i<n;++i){
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	while(e[rt].size()!=1)++rt;
	i64 v0=a[rt];
	f1(rt,0);
	if(a[rt]!=v0)flag=0;
	puts(flag?"YES":"NO");
	return 0;
}