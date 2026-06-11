#include <cstdio>
int a[100005],n;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
bool check(){
	int m=0;
	for (int i=1;i<=n;i++) m+=a[i]&1;
	if ((n-m)&1) return 1;
	if (m>1) return 0;
	int d=0;
	for (int i=1;i<=n;i++){
		a[i]^=a[i]&1;
		if (!a[i]) return 0;
		d=gcd(d,a[i]);
	}
	for (int i=1;i<=n;i++) a[i]/=d;
	return check()^1;
}
int main(){
	scanf("%d\n",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (check()) printf("First\n");
		else printf("Second\n");
}