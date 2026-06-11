#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
ll x[1000005],a[1000005],w[1000005];
int main(){
	ll n=read(),L=read(),T=read(),cur=0;
	for (ll i=0;i<n;i++){
		a[i]=read(); w[i]=read();
		if (w[i]==1){
			x[i]=(a[i]+T)%L;
			cur+=(a[i]+T)/L;
		} else{
			x[i]=(a[i]-T)%L;
			cur+=(a[i]-T)/L;
			if (x[i]<0) x[i]+=L,cur--;
		}
	}
	cur=(cur%n+n)%n;
	sort(x,x+n);
	for (ll i=cur;i<n;i++) printf("%lld\n",x[i]);
	for (ll i=0;i<cur;i++) printf("%lld\n",x[i]);
	return 0;
}