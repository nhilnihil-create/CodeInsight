#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int n,m,xx,b[N],x[N],tmp[N],ans[N],sum[N],tmpp[N];long long K;
inline void change1(){
	for (int i=1;i<=n;i++) tmpp[i]=ans[i];
	for (int i=1;i<=n;i++) ans[i]=tmp[tmpp[i]];
}
inline void change2(){
	for (int i=1;i<=n;i++) tmpp[i]=tmp[i];
	for (int i=1;i<=n;i++) tmp[i]=tmpp[tmpp[i]];
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&x[i]),b[i]=x[i]-x[i-1];
	scanf("%lld%lld",&m,&K);
	for (int i=1;i<=n;i++) tmp[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%lld",&xx);
		swap(tmp[xx],tmp[xx+1]);
	}
	for (int i=1;i<=n;i++) ans[i]=i;
	while (K){
		if (K&(int)1) change1();
		K=K/(int)2;change2();
	}
	for (int i=1;i<=n;i++) sum[i]=b[ans[i]];
	for (int i=1;i<=n;i++) sum[i]+=sum[i-1];
	for (int i=1;i<=n;i++) printf("%lld\n",sum[i]);
	return 0;
}