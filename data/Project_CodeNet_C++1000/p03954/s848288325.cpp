#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
const int N=100005;
int n,a[N<<1],b[N<<1];
int check(int x) {
	for(RI i=1;i<=2*n-1;++i) b[i]=(a[i]>=x);
	for(RI i=0;i<n;++i) {
		if(b[n-i]==b[n-i-1]) return b[n-i];
		if(b[n+i]==b[n+i+1]) return b[n+i];
	}
	return b[1];
}
int main()
{
	n=read();
	for(RI i=1;i<=2*n-1;++i) a[i]=read();
	int l=1,r=2*n-1,ans;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}