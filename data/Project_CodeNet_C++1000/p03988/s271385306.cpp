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
int n,h[110];
int main(){
	read(n);
	int mx=0;
	for(int i=1;i<=n;i++){
		int x;read(x);
		if(x>=n){puts("Impossible");return 0;}
		h[x]++;
		mx=max(mx,x);
	}
	int flag=1;
	if(~mx&1) flag&=h[mx+1>>1]==1;
	else flag&=h[mx+1>>1]==2;
	for(int i=mx;i>mx+1>>1;i--) flag&=h[i]>1;
	for(int i=1;i<mx+1>>1;i++) flag&=!h[i];
	if(flag) puts("Possible");
	else puts("Impossible");
	return 0;
}