#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10;
int N;
ll A[MAXN];
char C[MAXN];
ll f[3];

int main() {
	register int i;
	f[0] = f[1] = f[2] = -1e18;
	scanf("%d", &N);
	scanf("%lld", &f[0]);
	for(i = 1; i < N; ++i) {
		scanf(" %c", &C[i]);
		scanf("%lld", &A[i]);
		C[i] = C[i] == '+' ? 1 : -1;
		f[0] += A[i] * C[i];
		f[1] -= A[i] * C[i];
		f[2] += A[i] * C[i];
		if(C[i] == -1) f[2] = max(f[2], f[1]), f[1] = max(f[1], f[0]);
		f[1] = max(f[1], f[2]), f[0] = max(f[0], f[1]);
	}
	printf("%lld\n", f[0]);
	return 0;
}