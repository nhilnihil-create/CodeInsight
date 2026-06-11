#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000005
using namespace std;
const int mod = 1e9+7;

int n, f[N];

void upd(int &x, int y){ x += y; if(x >= mod) x -= mod; }

int main(){
	scanf("%d", &n);
	f[1] = n; f[2] = 1LL * n * n % mod;
	int sum = 0;
	for(int i = 3; i <= n; i++){
		f[i] = f[i - 1];
		upd(f[i], sum);
		upd(f[i], 1LL * (n - 1) * (n - 1) % mod);
		upd(f[i], n - i + 2);
		upd(sum, f[i - 2]);
	}
	printf("%d\n", f[n]);
}
