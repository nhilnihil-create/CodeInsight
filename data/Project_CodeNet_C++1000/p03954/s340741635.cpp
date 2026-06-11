#include <cstdio>
const int N=2e5+5;
int a[N],mid,l,r,n,ans=0;
inline bool get(int x){return !(x<=mid);}
inline bool check(){
	for (int i=1;i<n;i++){
		if (get(a[n+i-1])==get(a[n+i])) return get(a[n+i]);
		if (get(a[n-i+1])==get(a[n-i])) return get(a[n-i]);
	}return get(a[1]);
}
int main () {
	scanf ("%d",&n);
	for (int i=1;i<(n*2);i++) scanf ("%d",&a[i]);
	l=1,r=(n*2)-1;
	while (l<=r){
		mid=(l+r)>>1;
		if (check()) l=mid+1;
		else r=mid-1;
	}
	printf ("%d",r+1);
	return 0;
}