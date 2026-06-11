#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],fa[22][N],L,q,x,y;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d%d",&L,&q);
	for (int i=1;i<n;i++){
		int l=i+1,r=n;
		while (l<r){
			int mid=(l+r+1)/2;
			if (a[i]+L>=a[mid])l=mid;
			else r=mid-1;
		}
		fa[0][i]=l;
	} 
	fa[0][n]=n;
	for (int i=1;i<=19;i++)
		for (int j=1;j<=n;j++)fa[i][j]=fa[i-1][fa[i-1][j]];
	while (q--){
		scanf("%d%d",&x,&y);
		if (x==y){
			puts("0");
			continue;
		}
		if (x>y)swap(x,y);
		int ans=0;
		for (int i=19;i>=0;i--)
			if (fa[i][x]<y)x=fa[i][x],ans+=1<<i;
		printf("%d\n",ans+1);	
	}
}