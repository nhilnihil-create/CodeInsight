#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define maxn 200005
int m,n,x,y,ans,f[maxn],ni[maxn];
int f1(int a,int b){
	return (a += b) >= mod ? a - mod : a;
}
int f2(int a,int b){
	return (a -= b) < 0 ? a + mod : a;
}
int f3(int a,int b){
	return a * b % mod;
}
int f4(int a,int k){
	if(k == 0) return 1;
	if(k == 1) return a;
	int s = f4(a,k / 2) % mod;
	if(k % 2) return (s * s % mod) * a % mod;
	else return s * s % mod;
}
int C(int a,int b){
	return f3(f3(f[b],ni[a]),ni[b - a]);
}
int p(int xa,int ya,int xb,int yb){
	int n = xb - xa,m = yb - ya;
	return C(m ,n + m);
}
signed main(){
//	freopen("date.in","r",stdin);
//	freopen("date.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&x,&y); 
	f[0] = 1,ni[0] = 1;
	for(int i = 1; i <= maxn - 5; i++){
		f[i] = f3(f[i - 1],i) % mod;
		ni[i] = f4(f[i],mod - 2) % mod;
	}
	for(int i = 1; i <= n - x; i++){
		ans = f1(ans,f3(p(1,1,i,y) % mod,p(i,y + 1,n,m) % mod)) % mod;
	}
	printf("%lld",ans);
//	for(int i = 1; i <= 5; i++) printf("%lld\n",f[i])
//	printf("%lld",f4(3,4));
//	printf("%lld",p(1,1,4,4));
//	printf("%lld",f1(9,9));
	return 0;
}
