#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct P{
	int k,w;
}a[505];
int n,m,b[505],ans[300005];
bool cmp(P a,P b){
	return a.w<b.w;
}
bool solve(){
	for(int i=1;i<=n;i++) ans[b[i]]=i,a[i].k=i,a[i].w=b[i];
	sort(a+1,a+n+1,cmp);
	for(int i=m,pos=n,rst=n-a[n].k;i;i--){
		while(!rst&&pos) pos--,rst=n-a[pos].k;
		if(!pos) break;
		if(ans[i]) continue;
		ans[i]=a[pos].k;rst--;
		if(i<a[pos].w)
			return 0;
	}
	for(int i=1,pos=1,rst=a[1].k-1;i<=m;i++){
		while(!rst&&pos<n) pos++,rst=a[pos].k-1;
		if(ans[i]) continue;
		ans[i]=a[pos].k;rst--;
		if(i>a[pos].w)
			return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	m=n*n;
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	if(solve()){
		puts("Yes");
		for(int i=1;i<=m;i++) printf((i==m)?"%d":"%d ",ans[i]);
	}
	else puts("No");
	return 0;
}