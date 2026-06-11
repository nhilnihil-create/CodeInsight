#include<cstdio>
int n,x[100100],L,f[100100][25],Q,l,r;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	scanf("%d",&L);
	int pre=n;
	for(int i=n,pre=n;i>=1;i--){
		while(x[i]+L<x[pre])pre--;
		f[i][0]=pre;
	}
	for(int i=1;i<=20;i++)
		for(int j=1;j<=n;j++){
			if(f[j][i-1]==n)f[j][i]=n;
			else f[j][i]=f[f[j][i-1]][i-1];
		}
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&l,&r);
		if(l>r)l^=r^=l^=r;
		int ans=0;
		for(int i=20;i>=0;)
			if(f[l][i]<r)ans+=1<<i,l=f[l][i];
			else i--;
		printf("%d\n",ans+1);
	}
} 