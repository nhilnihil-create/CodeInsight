#include<bits/stdc++.h>
using namespace std;
#define N 111116
typedef long long ll;

ll n,m,k,x[N],r[N];

void mul(ll a[],ll b[]){
	static ll c[N];
	for (int i=1;i<=n;i++) c[i]=a[r[i]];
	memcpy(a,c,sizeof(c));
}

ll read(){
	ll x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')  f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();
	for (int i=1;i<=n;i++) x[i]=read();
	for (int i=n;i>=1;i--) x[i]-=x[i-1];
	for (int i=1;i<=n;i++) r[i]=i; 
	m=read();k=read();
	for (int i=1,t;i<=m;i++)
		t=read(),swap(r[t],r[t+1]);
	for (;k;mul(r,r),k/=2)
		if (k%2) mul(x,r);
	for (int i=1;i<=n;i++)
		printf("%lld.0\n",x[i]+=x[i-1]);
	return 0;
}