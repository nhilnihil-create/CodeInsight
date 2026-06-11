#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int n,a[100100];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
bool solve(){
	int s=0;
	for(int i=1;i<=n;i++) s+=~a[i]&1;
	if(s&1) return 1;
	if(n-s>1) return 0;
	int g=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) return 0;
		g=gcd(g,a[i]&-2);
	}
	for(int i=1;i<=n;i++) a[i]/=g;
	return !solve();
}
int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	if(solve()) puts("First");
	else puts("Second");
	return 0;
}
