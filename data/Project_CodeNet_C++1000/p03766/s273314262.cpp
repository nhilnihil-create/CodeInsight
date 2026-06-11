#include<bits/stdc++.h>
typedef long long i64;
const int P=1e9+7,N=1e6+7;
int n;
i64 ans=0,a[N],b[N];
int main(){
	scanf("%d",&n);
	a[0]=a[1]=a[2]=1,a[3]=2;
	i64 s=5;
	for(int i=4;i<=n;++i){
		a[i]=(s-a[i-2])%P;
		s=(s+a[i])%P;
	}
	b[0]=1,b[1]=n-1,b[2]=i64(n-1)*n%P;
	for(int i=3;i<=n;++i)b[i]=b[i-1]-1;
	for(int i=0;i<=n;++i)ans=(ans+a[i]*b[n-i])%P;
	printf("%lld\n",(ans+P)%P);
	return 0;
}