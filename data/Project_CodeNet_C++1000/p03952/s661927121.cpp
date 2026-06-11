#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(register int i=(a);i>=(b);--i)
#define LL long long
#define MaxN 2000010
using namespace std;
int N,M,A[MaxN],Now,Vis[MaxN];
int main(){
	scanf("%d%d",&N,&M);
	if(N==1){printf(M==1?"Yes\n1\n":"No");return 0;}
	if(N==2){printf(M==2?"Yes\n1\n2\n3\n":"No");return 0;}
	if((M==1)||(M==2*N-1)){puts("No");return 0;};
	A[N]=M,A[N+1]=1,A[N-1]=2*N-1;
	Vis[1]=Vis[M]=Vis[2*N-1]=1;
	For(i,1,2*N-1){
		if(i>=N-1&&i<=N+1)continue;
		while(Vis[++Now]);A[i]=Now;
	}
	puts("Yes");For(i,1,2*N-1)printf("%d\n",A[i]);
	return 0;
}