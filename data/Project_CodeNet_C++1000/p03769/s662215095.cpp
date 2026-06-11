#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a[205],L,R,now;
ll cnt;

inline void solve(){
	int i=40; L=101,R=L-1;
	for(;!((1ll<<i)&cnt);i--);
	for(i--;i>=0;i--){
		a[++R]=++now;
		if((1ll<<i)&cnt) a[--L]=++now;
	}
	
	n=R-L+1;
	for(int i=1;i<=n;i++) a[i]=a[i+L-1];
	for(int i=n+1;i<=n*2;i++) a[i]=i-n;
	n<<=1;
}

int main(){
	scanf("%lld",&cnt),cnt++;
	solve(),printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
	return 0; 
}