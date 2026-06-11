#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m;
long long ans[N*2];
int main(){
	scanf("%d%d",&n,&m);
	long long add=0;
	for(int i=1,last,now;i<=n;i++){
		scanf("%d",&now);
		if(now<last) now+=m;
		if(i!=1&&now!=last){
			add+=now-last;
			ans[now+1]+=1;
			ans[last+2]+=-1;
			ans[now+1]+=now-last-1;
			ans[now+2]+=last-now+1;
		}
		last=(now-1)%m+1;
	}
	for(int i=1;i<=m*2;i++) ans[i]+=ans[i-1];
	for(int i=1;i<=m*2;i++) ans[i]+=ans[i-1];
	long long out=1e18;
	for(int i=1;i<=m;i++) out=min(out,ans[i]+ans[i+m]+add);
	cout<<out<<endl;
	return 0;
} 