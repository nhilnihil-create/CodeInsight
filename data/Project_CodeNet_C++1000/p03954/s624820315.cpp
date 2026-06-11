#include<cstdio>
using namespace std;
int n,a[1000005],l,r,mid,ans,xl,xr;
bool b[1000005];
bool check(int x){
	xl=0;xr=n<<1;
	for (register int i=1;i<=(n<<1)-1;++i) b[i]=(a[i]>=x);
	for (register int i=n;i>=2;--i){
		if (b[i]==b[i-1]) {xl=i;break;}
	}
	for (register int i=n;i<(n<<1)-1;++i){
		if (b[i]==b[i+1]) {xr=i;break;}
	}
	if (xl==0&&xr==n*2) return b[1];
	return n-xl>xr-n?b[xr]:b[xl];
}
int main(){
	scanf ("%d",&n);
	for (register int i=1;i<=(n<<1)-1;++i) scanf ("%d",&a[i]);
	l=1;r=(n<<1)-1;
	while (l<=r){
		mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf ("%d\n",ans);
	return 0;
}