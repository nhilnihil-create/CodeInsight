#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct aaa{
	int x,y;
}a[500010];
int n,m,ans,f[500010];
bool cmp(aaa a,aaa b){
	return a.y-a.x<b.y-b.x;
}
int lowbit(int x){
	return x&(-x);
}
void ins(int x,int w){
	int i;
	for(i=x;i<=m;i+=lowbit(i))f[i]+=w;
}
int query(int x){
	int i,xlh=0;
	for(i=x;i;i-=lowbit(i))xlh+=f[i];
	return xlh;
}
int main(){
	int i,j=0,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=m;i++){
		while(j<n&&a[j+1].y-a[j+1].x<i){
			j++;
			ins(a[j].x,1);ins(a[j].y+1,-1);
		}
		ans=0;
		for(k=i;k<=m;k+=i)ans+=query(k);
		printf("%d\n",ans+n-j);
	}
}