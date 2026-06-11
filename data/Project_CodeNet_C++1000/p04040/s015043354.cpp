#include <cstdio>
const int N = 200005, p = 1000000007;
long long fac[N], inv[N];
int qp(int x, int y) {
	int res = 1;
	for(; y; y >>= 1, x = (long long)x*x%p) if(y&1) res = (long long)res*x%p;
	return res;
}
void init(int n){
	fac[0]=1;
	for(int i = 1; i <= n; i ++ ) fac[i] = fac[i-1]*i%p;
	inv[n] = qp(fac[n], p-2);
	for(int i = n; i >= 1; i -- ) inv[i-1] = inv[i]*i%p;
}
long long C(int n,int m) {
	return fac[n]*inv[m]%p*inv[n-m]%p;
}
int main(){
	int H, W, A, B, ans = 0;
	scanf("%d%d%d%d", &H, &W, &A, &B);
	init(H+W);
	for(int i=1;i<=H-A;i++)
		ans=(ans+C(i+B-2, i-1)*C(H+W-i-B-1, H-i))%p;
	printf("%d\n", ans);
}
