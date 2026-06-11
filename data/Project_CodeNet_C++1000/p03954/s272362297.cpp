#include<bits/stdc++.h>
using namespace std;
const int Max_N=1e5;
int N,A[Max_N*2+10]={},B[Max_N*2+10]={};
inline int Chck(int x){
	if(B[N-1]==B[N]||B[N]==B[N+1]) return B[N];
	int L=N-2,R=N+2;
	for(;L>=1&&R<=2*N-1;){
		if(B[L]==B[L+1]) return B[L];
		if(B[R]==B[R-1]) return B[R];
		--L; ++R;
	} 
	return B[1];
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=2*N-1;i++) scanf("%d",&A[i]);
	int l=1,r=2*N-1;
	for(;l+1<r;){
		int mid=(l+r)/2;
		for(int i=1;i<=2*N-1;i++) 
		 if(A[i]<=mid) B[i]=0;
		 else B[i]=1;
		if(Chck(mid)==0) r=mid;
		else l=mid;
	}
	for(int i=1;i<=2*N-1;i++) 
	 if(A[i]<=r) B[i]=0;
	 else B[i]=1;
	if(Chck(r)==0) printf("%d\n",r);
	else printf("%d\n",l);
	return 0;
}