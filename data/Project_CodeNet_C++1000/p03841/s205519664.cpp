#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,f[N],ans[N];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		int x; scanf("%d",&x); f[x]=i;
	}
	for (int i=1,j=1;i<=n*n;++i){
		if (f[i]){
			ans[i]=f[i];
			for (int k=1;k<f[i];++k){
				for (;ans[j];++j);
				ans[j]=f[i];
			}
			if (j>i){puts("No"); return 0;}
		}
	}
	for (int i=n*n,j=n*n;i;--i){
		if (f[i]){
			for (int k=f[i]+1;k<=n;++k){
				for (;ans[j];--j);
				ans[j]=f[i];
				if (j<i){puts("No"); return 0;}
			}
		}
	}
	puts("Yes");
	for (int i=1;i<=n*n;++i) printf(i==n*n?"%d\n":"%d ",ans[i]);
	
	return 0;
}
			