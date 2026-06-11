#include<bits/stdc++.h>
using namespace std;

int N,M;long long K;
long long X[100005],D[100005];

int P[61][100005];
int ans[100005];

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%lld",&X[i]),D[i]=X[i]-X[i-1],P[0][i]=i;
	scanf("%d%lld",&M,&K);
	while(M--){
		int x;scanf("%d",&x);
		swap(P[0][x],P[0][x+1]);
	}
	for(int i=1;i<=60;i++)
	for(int j=1;j<=N;j++)
		P[i][j]=P[i-1][P[i-1][j]];
	for(int j=1;j<=N;j++) ans[j]=j;
	for(int i=60;~i;i--)if((K>>i)&1)
	for(int j=1;j<=N;j++)
		ans[j]=P[i][ans[j]];
	for(int i=1;i<=N;i++) printf("%lld\n",X[i]=X[i-1]+D[ans[i]]);
}