#include<bits/stdc++.h>
using namespace std;
int n,l,q,a[100005],b[100005][21];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&l);
	int dem=1,sum=0;
	for(int i=2;i<=n;i++){
		sum+=a[i]-a[i-1];
		while(sum>l){
			b[dem][0]=i-1;
			dem++;
			sum-=(a[dem]-a[dem-1]);
		}
	}
	for(int i=dem;i<=n;i++){
		b[i][0]=n;
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			b[i][j]=b[b[i][j-1]][j-1];
		}
	}
	scanf("%d",&q);
	while(q--){
		int u,v;
		scanf("%d %d",&u,&v);
		if(u>v) swap(u,v);
		int ans=1;
		for(int i=log2(n);i>=0;i--){
			if(b[u][i]<v){
				u=b[u][i];
				ans+=(1<<i);
			}
		}
		printf("%d\n",ans);
	}
}