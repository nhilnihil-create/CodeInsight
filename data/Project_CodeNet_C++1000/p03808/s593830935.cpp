#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 1e5 + 500;

int n;
ll A[N], P[2 * N], pot, P2[2 * N];

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%lld", A + i);
		pot += A[i];
	}
	if(pot % ((ll)n * (n + 1) / 2) != 0){
		printf("NO\n");
		return 0;
	}
	pot /= (ll)n * (n + 1) / 2;
	for(int i = 0;i < n;i++){
		ll x = pot - (A[i] - A[(n + i - 1) % n]);
		if(x % (ll)n != 0 || x < 0){
			printf("NO\n");
			return 0;
		}
		x /= n;
		P[i] += x; P[i + n] -= x;
		P2[i + n] -= x * n;
	}
	for(int i = 1;i < 2 * n;i++)
		P[i] += P[i - 1];
	P2[0] += P[0];
	for(int i = 1;i < 2 * n;i++)
		P2[i] += P2[i - 1] + P[i];
	for(int i = 0;i < n;i++){
		if(A[i] != P2[i] + P2[i + n]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
