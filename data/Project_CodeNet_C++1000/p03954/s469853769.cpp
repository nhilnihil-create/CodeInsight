#include<bits/stdc++.h>
#define ll long long
#define inf(x) (ll)(1e##x)
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int n,a[201000],h[201000];
bool check(int lim){
	for(int i=1;i<2*n;i++) h[i]=a[i]>=lim;
	if(h[n]==h[n-1]||h[n]==h[n+1]) return h[n];
	for(int i=1;i<n;i++){
		if(h[n-i]==h[n-i-1]) return h[n-i];
		if(h[n+i]==h[n+i+1]) return h[n+i];
	}
	if(n&1) return h[n];
	else return !h[n];
}
int main(){
	read(n);
	for(int i=1;i<2*n;i++) read(a[i]);
	int l=1,r=2*n;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<'\n';
	return 0;
}