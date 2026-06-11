// luogu-judger-enable-o2
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int M,N,A[200010];
bool check(int md){
	for(int i=M;i>=1;i--){
		int ls=N+1-i,rs=N+2-i;
		if((A[i]>md ^ A[i-1]<=md) && A[i-1]!=0)	return A[i]>md;
		if((A[rs]>md ^ A[ls]<=md) && A[ls]!=0)	return A[rs]>md;
	}
	return A[1]>md;
}
int main(){
	scanf("%d",&M);N=2*M-1;
	for(int i=1;i<=N;i++)	scanf("%d",&A[i]);
	int L=1,R=1000010,m=0;
	while(L+1<R){
		m=(L+R)>>1;
		if(check(m))	L=m;
		else	R=m;
	}
	printf("%d\n",R);
	return 0;
}