#include<cstdio>
#define ll long long
int h[100000],n,a,b;
bool check(int t) {
	int c=0;
	for(int i = 1; i <= n && c <= t; i++ )
		c+=h[i]<=(ll)t*b?0:(h[i]-t*b+a-1)/a;
	return c<=t;
}
int main() {
	scanf("%d%d%d",&n,&a,&b),a-=b;
	for(int i = 1; i <= n; i ++ )scanf("%d", &h[i]);
	int l=1, r=1e9;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
}