#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,m,c[N];
struct data{
	int l,r;
}a[N];
bool cmp(data a,data b){
	return a.r-a.l+1<b.r-b.l+1;
}
void add(int i,int v){
	i++;
	while(i<=m+1){
		c[i]+=v;
		i+=i&(-i);
	}
}
int sum(int i){
	i++;
	int res=0;
	while(i){
		res+=c[i];
		i-=i&(-i);
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	sort(a+1,a+n+1,cmp);
	int now=0;
	for(int i=1;i<=m;i++){
		int ans=n-now;
		for(int j=i;j<=m;j+=i){
			ans+=sum(j);
		}
		printf("%d\n",ans);
		while(now<n&&a[now+1].r-a[now+1].l+1<=i){
			now++;
			add(a[now].l,1);
			add(a[now].r+1,-1);
		}
	}
	return 0;
}