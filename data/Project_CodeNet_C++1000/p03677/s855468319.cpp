#include <bits/stdc++.h>
const int N=100005;
typedef long long ll;
ll sum,s[N],b[N];
int n,m,a[N];
void modify(ll *a,int l,int r,int val){
	a[l]+=val,a[r+1]-=val;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n;i++){
		int x=a[i-1],y=a[i];
		if (x>y){
			sum=sum+y+m-x;	
			modify(s,1,y,-(x-m)-1);
			modify(b,1,y,1);
			modify(s,x+1,m,-x-1);
			modify(b,x+1,m,1);
		}else{
			sum=sum+y-x;
			modify(s,x+1,y,-x-1);
			modify(b,x+1,y,1);
		}
	}
	ll ans=0;
	for (int i=1;i<=m;i++) b[i]+=b[i-1],s[i]+=s[i-1];
	for (int i=1;i<=m;i++) ans=std::max(ans,b[i]*i+s[i]);
	printf("%lld\n",sum-ans);
}