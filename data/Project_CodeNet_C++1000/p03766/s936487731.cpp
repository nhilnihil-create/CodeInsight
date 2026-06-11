#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MD = 1e9+7;
long long n, a[1000005];
int main(){
	scanf("%lld", &n);
	a[1] = n; a[2] = (n*n + n) % MD; a[3] = 3*n*n % MD;
	for(int i = 4; i <= n; i++) a[i] = (a[i-1]*2 - a[i-2] + a[i-3] + 3 - i + n*(n-1)) % MD;
	printf("%lld\n", (a[n] - a[n-1] + MD) % MD);
}