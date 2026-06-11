#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,a[200010],b[200010];
bool check(int mid){
	for(int i=1;i<2*n;++i)b[i]=a[i]<=mid;
	for(int i=0;i+1<n;++i){
		if(b[n+i]==b[n+i+1])return b[n+i];
		if(b[n-i]==b[n-i-1])return b[n-i];
	}
	return b[1];
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<2*n;++i)a[i]=gi();
	int l=1,r=2*n-1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
