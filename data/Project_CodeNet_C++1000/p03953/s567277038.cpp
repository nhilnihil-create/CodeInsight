#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MaxN=1e5+5;

int N,M;
LL K;
int X[MaxN],A[MaxN],D[MaxN];
int Base[MaxN],Ans[MaxN],Tmp[MaxN];

void Mul(int *a,int *b){
	int i;
	for(i=1;i<N;i++)
		Tmp[i]=b[a[i]];
	memmove(a,Tmp,sizeof(a));
}

int main(){
	int i,j;
	LL now;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&X[i]);
		Base[i]=Ans[i]=Tmp[i]=i;
	}
	for(i=1;i<N;i++)
		D[i]=X[i+1]-X[i];
	scanf("%d%lld",&M,&K);
	for(i=1;i<=M;i++)
		scanf("%d",&A[i]);
	for(i=1;i<=M;i++)
		swap(Tmp[A[i]-1],Tmp[A[i]]);
	for(i=1;i<N;i++)
		Base[Tmp[i]]=i;
	for(;K;K>>=1){
		if(K&1){
			for(j=1;j<N;j++)
				Tmp[j]=Base[Ans[j]];
			memmove(Ans,Tmp,sizeof(Ans));
		}
		for(j=1;j<N;j++)
			Tmp[j]=Base[Base[j]];
		memmove(Base,Tmp,sizeof(Base));
	}
	for(i=1;i<N;i++)
		Tmp[Ans[i]]=i;
	for(now=X[i=1];i<=N;i++){
		printf("%lld\n",now);
		now+=D[Tmp[i]];
	}
	return 0;
}