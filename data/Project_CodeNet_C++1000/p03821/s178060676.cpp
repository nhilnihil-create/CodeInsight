#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 500;
const int MOD = 1e9 + 7;

int A[N], B[N], n;
ll sol = 0;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d%d", A + i, B + i);
	for(int i = n - 1;i >= 0;i--){
		sol += (B[i] - (sol + A[i]) % B[i]) % B[i];
	}
	printf("%lld\n", sol);
	return 0;
}
