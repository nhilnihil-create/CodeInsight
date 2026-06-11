#include<bits/stdc++.h>
using namespace std;
const int Max_N=1e5,Max_Q=1e5;
int N,L,Q,X[Max_N+10]={},f[Max_N+10][22]={};
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&X[i]);
	scanf("%d",&L);
	for(int i=1,r=1;i<=N;i++){
		for(;X[r+1]-X[i]<=L&&r+1<=N;++r);
		f[i][0]=r;
	}
	for(int i=1;i<=20;i++)
	 for(int j=1;j<=N;j++)
	  f[j][i]=f[f[j][i-1]][i-1];
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		int a,b,Sum=0; scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		for(int j=20,x=a;j>=0;j--)
		 if(f[x][j]<b) x=f[x][j],Sum+=(1<<j);
		Sum+=1;
		printf("%d\n",Sum);
	}
	return 0;
}