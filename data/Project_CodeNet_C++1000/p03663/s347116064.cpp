#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector <int> A,B;
const LL O=1000000000;
int w,N,K; char c,S[3];
char go(LL n){
	/*A.clear(); B.clear(); LL x=n,y=N;
	while (x) A.push_back(x%10),x/=10;
	while (y) B.push_back(y%10),y/=10;
	for (int i=0;i<A.size()/2;++i) swap(A[i],A[A.size()-i-1]);
	for (int i=0;i<B.size()/2;++i) swap(B[i],B[B.size()-i-1]);
	if (n<=N^A<=B) return 'N'; return 'Y';*/
	printf("? %lld\n",n);
	fflush(stdout);
	scanf("%s",S);
	return S[0];
}
int fuck(int l,int r){
	if (l==r) return l;
	return go(O*(w*10+(l+r>>1))+O-1)=='N'?
	fuck((l+r>>1)+1,r):fuck(l,l+r>>1);
}
int main(){
	//scanf("%d",&N);
	for (int i=1,x=10;i<=9;++i,x*=10){
		c=go(x);
		if (c=='N') {K=i; break;}
	}
	if (!K)
	for (int i=9,x=O-1;i;--i,x/=10){
		c=go(x);
		if (c=='N') {K=i+1; break;}
	}
	if (!K) {puts("! 1"); return 0;}
	if (K==10) {printf("! %lld\n",O); fflush(stdout);return 0;}
	w=w*10+fuck(1,9);
	for (int i=2;i<=K;++i) w=w*10+fuck(0,9);
	printf("! %d\n",w);
	fflush(stdout);
	return 0;
}