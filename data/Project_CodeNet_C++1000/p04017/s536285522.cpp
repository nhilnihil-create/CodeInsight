#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn],anc[maxn][22];
int main(){
	int n,q,l;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d%d",&l,&q);
	for(int i=n;i>=1;i--){
		anc[i][0]=lower_bound(a+1,a+n+1,a[i]+l)-a;
		if(anc[i][0]>n)anc[i][0]=n;
		if(a[anc[i][0]]>a[i]+l)anc[i][0]--;
		for(int j=1;j<=21;j++){
			anc[i][j]=anc[anc[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=0;
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		for(int j=21;j>=0;j--){
			if(anc[x][j]<y){
				ans+=pow(2,j);
				x=anc[x][j];
			}
		}if(x<y)ans++;
		printf("%d\n",ans);
	}
}