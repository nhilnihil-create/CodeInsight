#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define R register
#define Maxn 200002

inline void read(int &x){
	static int ch; static bool flag;
	for(flag=0,ch=getchar(); ch<'0'||ch>'9'; ch=getchar()) flag |= ch=='-';
	for(x=0; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1) + (x<<3) + ch-48;
	x = flag ? -x : x;
}

int N,M,A[Maxn];
ll Ans,Sum,B[Maxn];

int main()
{
	read(N),read(M);
	for(R int i=1;i<=N;++i) read(A[i]);
	for(R int i=1;i<N;++i){
		R int l=A[i], r=A[i+1];
		if(l>r) r+=M;
		Sum+=r-l;
		if(l!=r) 
			B[l+2]++, B[r+1]-=(r-(l+2)+1)+1, B[r+2]+=r-(l+2)+1;		
	}
	for(R int i=1;i<=M*2;++i) B[i]+=B[i-1];
	for(R int i=1;i<=M*2;++i) B[i]+=B[i-1];
	Ans=Sum;
	for(R int i=1;i<=M;++i) 
		Ans=min(Ans,Sum-B[i]-B[i+M]);
	printf("%lld\n",Ans);
	return 0;
}