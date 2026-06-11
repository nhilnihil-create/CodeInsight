#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
#define S(i) ((int)(A[i]>=Pos))
#define LL long long
using namespace std;
int N,A[300001],INF=10000000;
bool Check(int Pos){
	int m[2];
	m[0]=m[1]=INF;
//	For(i,1,2*N-1) printf("%d ",S(i));puts("");
	For(i,N,2*N-2)
		if(S(i)==S(i+1)){
			m[S(i)]=min(m[S(i)],i-N);
//			cout<<'-'<<i<<' '<<S(i)<<endl;
			break;
		}
	Rof(i,N,2)
		if(S(i)==S(i-1)){
			m[S(i)]=min(m[S(i)],N-i);
			break;
		}
//	cout<<m[1]<<' '<<m[0]<<endl;
	if(m[0]==INF&&m[1]==INF)return (S(N)^(N&1)^1);
	if(m[1]<m[0])return 1;
	return 0;
}
int main(){
	scanf("%d",&N);For(i,1,2*N-1) scanf("%d",&A[i]);
	int l=1,r=2*N-1,Mid,Ans;
//	cout<<Check(4);

	while(l<=r){
		Mid=l+r>>1;
		if(Check(Mid))
			Ans=Mid,l=Mid+1;
		else
			r=Mid-1;
	}

	printf("%d\n",Ans);

	return 0;
}
/*
3
1 5 2 4 3
*/