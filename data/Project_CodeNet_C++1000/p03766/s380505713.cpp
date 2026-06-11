#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MX = 1000005;
const int MM = 1000000007;

char A[MX], B[MX];
ll X[MX], Y[MX];
int N;

int main()
{
	scanf("%d", &N);
	X[0] = Y[0] = 1; X[1] = N; Y[1] = N + 1; 
	for(int i = 2; i <= N; i++){
		ll t = (i >= 3 ? Y[i-3] : 0) + (N-i+1);
		X[i] = (X[i-1] + t + (ll)(N-1) * (N-1)) % MM;
		Y[i] = (Y[i-1] + X[i]) % MM;
	}
	printf("%lld\n", X[N]);
}
