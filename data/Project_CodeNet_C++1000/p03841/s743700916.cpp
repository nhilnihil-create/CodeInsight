#include<bits/stdc++.h>
using namespace std;
const int N=505;
int ans[N*N],x[N],f[N],n;
int cmp(int a,int b){
	return x[a]<x[b];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&x[i]),f[i]=i;
	sort(f+1,f+n+1,cmp);
	int k=1;
	for (int i=1;i<=n;i++){
		ans[x[f[i]]]=f[i];
		for (int j=1;j<f[i];j++){
			while (ans[k])k++;
			if (k>x[f[i]]){
				puts("No");
				return 0;
			}
			ans[k]=f[i];
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n-f[i];j++){
			while (ans[k])k++;
			if (k<x[f[i]]){
				puts("No");
				return 0;
			}
			ans[k]=f[i];
		}
	puts("Yes");
	for (int i=1;i<=n*n;i++)printf("%d ",ans[i]);
}