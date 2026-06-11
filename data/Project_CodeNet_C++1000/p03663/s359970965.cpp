#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector <int> A,B;
const LL O=1000000000;
int w,N,K; char c,S[3];
char go(LL n){
	cout<<"? "<<n<<endl;
	cin>>c; return c;
}
int fuck(int l,int r){
	if (l==r) return l;
	return go(O*(w*10+(l+r>>1))+O-1)=='N'?
	fuck((l+r>>1)+1,r):fuck(l,l+r>>1);
}
int main(){
	for (int i=1,x=10;i<=9;++i,x*=10){
		c=go(x);
		if (c=='N') {K=i; break;}
	}
	if (!K)
	for (int i=9,x=O-1;i;--i,x/=10){
		c=go(x);
		if (c=='N') {K=i+1; break;}
	}
	if (!K) {cout<<"! 1"<<endl; return 0;}
	if (K==10) {cout<<"! "<<O<<endl; return 0;}
	w=w*10+fuck(1,9);
	for (int i=2;i<=K;++i) w=w*10+fuck(0,9);
	cout<<"! "<<w<<endl;
	return 0;
}