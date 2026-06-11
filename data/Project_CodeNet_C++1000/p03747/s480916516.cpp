#include<bits/stdc++.h>
using namespace std;

int N,L,T;
int X[100005];
int rnk;

int main(){
	scanf("%d%d%d",&N,&L,&T);
	for(int i=0;i<N;i++){
		int w;scanf("%d%d",&X[i],&w);
		if(w==1) X[i]+=T;else X[i]-=T;
		rnk+=X[i]/L;
		rnk-=(X[i]%L<0);
		X[i]=(X[i]%L+L)%L;
	}
	rnk=(rnk%N+N)%N;
	sort(X,X+N);
	for(int i=0;i<N;i++)
		printf("%d\n",X[(i+rnk)%N]);
}