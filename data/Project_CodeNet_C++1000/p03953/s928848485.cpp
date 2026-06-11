#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 500;
const int LOG = 60;

int n, a[N], m, P[N][60];
ll k, x[N], dx[N];

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%lld", x + i);
	for(int i = 1;i < n;i++){
		dx[i] = x[i] - x[i - 1];
		P[i][0] = i;
	}	
	scanf("%d%lld", &m, &k);
	for(int i = 0;i < m;i++){
		scanf("%d", a + i), a[i]--;
		swap(P[a[i]][0], P[a[i] + 1][0]);
	}	
	for(int j = 1;j < 60;j++)
		for(int i = 1;i < n;i++){
			P[i][j] = P[P[i][j - 1]][j - 1];
	}
	ll cur = x[0];
	for(int i = 0;i < n;i++){
		int gdje = i;
		for(int j = 0;j < 60;j++)
			if((1LL << j) & k)
				gdje = P[gdje][j];
		cur += dx[gdje];
		printf("%lld\n", cur);
	}
}