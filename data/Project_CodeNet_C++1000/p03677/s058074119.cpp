#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
ll n,m,l,r,an,ab,ans,a[100005],b[200005],c[200005];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<n;i++){
		l=a[i],r=a[i+1];
		if(r<l)r+=m;
		an+=r-l;
		if(l+1<r){
			b[l+2]++,c[l+2]-=l+1;
			b[r+1]--,c[r+1]+=l+1;
		}
	}
	for(int i=1;i<=m+m;i++){
		b[i]+=b[i-1];
		c[i]+=c[i-1];
	}
	for(int i=1;i<=m;i++){
		ab=b[i]*i+c[i]+b[i+m]*(i+m)+c[i+m];
		if(ab>ans)ans=ab;
	}
	printf("%lld",an-ans);
	return 0;
}