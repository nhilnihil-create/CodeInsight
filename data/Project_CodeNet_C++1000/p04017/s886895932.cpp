#include<bits/stdc++.h>
using namespace std;
int n,a[100010],Q,L,f[100010][31];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&L);
	for(int i=1,pos=2;i<=n;i++){
		while(pos<=n&&a[pos]-a[i]<=L) pos++;
		f[i][0]=pos-1;
	}
	for(int i=1;i<=30;i++)
		for(int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	scanf("%d",&Q);
	while(Q--){
		int x,y,num=0;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		for(int i=30;i>=0;i--){
			if(f[x][i]>=y) continue;
			num+=(1<<i); x=f[x][i];
		}
		printf("%d\n",num+1);
	}
	return 0;
}